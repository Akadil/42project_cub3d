/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_3d_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:01:35 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/19 20:00:29 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct s_point
{
	int	i;
	int	j;
	int	color;
	int	x_p;
	int	y_p;
}		t_point;

void	ft_set_params(t_data *my_data, int width, int height);
void	ft_render_3d(t_data *data, int x_offset);

void    ft_rendering_3d_object(t_data *data)
{
    t_vector    sprite;
    t_vector    sprite_p;
    double      inv_det;
    int         screen_x;
    int         sprite_height;
    int         sprite_width;
    int         draw_start_y;
    int         draw_start_x;
    int         draw_end_x;
    int         draw_end_y;         
    
    /*  Sprite position */
    sprite.x = data->sprite_pos.x - data->player.x;
    sprite.y = data->sprite_pos.y - data->player.y;

    /*  Determinant */
    inv_det = 1.0 / (data->view.plane.x * data->view.dir.y - data->view.plane.y * data->view.dir.x);
    
    /*  Transformed position    */
    sprite_p.x = inv_det * (data->view.dir.y * sprite.x - data->view.dir.x * sprite.y);
    sprite_p.y = inv_det * (-1 * data->view.plane.y * sprite.x + data->view.plane.x * sprite.y);
	if (sprite_p.y <= 0)
    	return ;
	// printf("Initially %lf\n", sprite_p.y);

    screen_x = (double)WINDOW_WIDTH / 2 * (1.0 + sprite_p.x / sprite_p.y);

    sprite_height = abs ((int)((double)WINDOW_HEIGHT / sprite_p.y));
    draw_start_y = -1.0 * sprite_height / 2 + (double)(WINDOW_HEIGHT) / 2;
    draw_end_y = (double)sprite_height / 2 + (double)(WINDOW_HEIGHT) / 2;
    sprite_width = abs( (int) ((double)WINDOW_HEIGHT / sprite_p.y));
    draw_start_x = -1.0 * sprite_width / 2 + screen_x;
    draw_end_x = sprite_width / 2 + screen_x;

    ft_set_params(data, draw_end_x - draw_start_x, draw_end_y - draw_start_y);
    if (draw_start_y < 0) 
        draw_start_y = 0;
    if (draw_end_y >= WINDOW_HEIGHT)
        draw_end_y = WINDOW_HEIGHT - 1;
    if (draw_start_x < 0)
        draw_start_x = 0;
    if (draw_end_x >= WINDOW_WIDTH)
	draw_end_x = WINDOW_WIDTH - 1;
    data->fdf.length = sprite_p.y;
	data->fdf.pos.x = sprite.x;
	data->fdf.pos.y = sprite.y;
	data->fdf.pos_p.x = sprite_p.x;
	data->fdf.pos_p.y = sprite_p.y;
	// printf("1. %lf of %lf\n", data->fdf.pos_p.y, sprite_p.y);

	// I think I have to pass the draw_start !
    ft_render_3d(data, draw_start_x);
}

float	ft_rad(int angle);

void	ft_transform(t_fdf *data, int i, int j)
{
	double	x_p;
	double	y_p;
	double		x;
	double		y;
	double		z;

	x = (double)data->mtrx.node[i][j].x * data->param.grid;
	y = (double)data->mtrx.node[i][j].y * data->param.grid;
	z = (double)data->mtrx.node[i][j].z * data->param.attitude;

	x_p = 0.0;
	x_p += x * cos(ft_rad(data->param.theta)) * cos(ft_rad(data->param.beta));
	x_p -= z * sin(ft_rad(data->param.beta));
	x_p -= y * sin(ft_rad(data->param.theta)) * cos(ft_rad(data->param.beta));
	x_p += data->param.x_offset;

	y_p = 0.0;
	y_p += x * sin(ft_rad(data->param.theta)) * cos(ft_rad(data->param.alpha));
	y_p += y * cos(ft_rad(data->param.theta)) * cos(ft_rad(data->param.alpha));
	y_p += x * cos(ft_rad(data->param.theta)) * sin(ft_rad(data->param.beta))
		* sin(ft_rad(data->param.alpha));
	y_p -= y * sin(ft_rad(data->param.theta)) * sin(ft_rad(data->param.beta))
		* sin(ft_rad(data->param.alpha));
	y_p += z * cos(ft_rad(data->param.beta)) * sin(ft_rad(data->param.alpha));
	y_p += data->param.y_offset;
	
	data->mtrx.node[i][j].x_p = (int)x_p;
	data->mtrx.node[i][j].y_p = (int)y_p;
}

float	ft_rad(int angle)
{
	return (angle * (3.142857 / 180.0));
}



void	ft_set_x_y(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->fdf.mtrx.height)
	{
		j = 0;
		while (j < data->fdf.mtrx.width)
		{
			ft_transform(&data->fdf, i, j);
			j++;
		}
		i++;
	}
}

void	ft_draw_line(t_data *data, int i, int j, int direct, int x_offset);

void	ft_render_3d(t_data *data, int x_offset)
{
	int	i;
	int	j;

	ft_set_x_y(data);
	i = 0;
	while (i < data->fdf.mtrx.height)
	{
		j = 0;
		while (j < data->fdf.mtrx.width)
		{
			if (j + 1 != data->fdf.mtrx.width)
				ft_draw_line(data, i, j, 1, x_offset);
			if (i + 1 != data->fdf.mtrx.height)
				ft_draw_line(data, i, j, 0, x_offset);
			j++;
		}
		i++;
	}
}



/*  -----------------------------------------------------------------------------   */
                            /*  Drawing the line    */
/*  -----------------------------------------------------------------------------   */

int	ft_abs(int a, int b);
int	ft_slope(int a, int b);
void	bresenhams(t_data *data, t_point p1, t_point p2, int x_offset);
void	ft_pixel(t_data *data, int x, int y, int color, int x_offset);

void	ft_draw_line(t_data *data, int i, int j, int direct, int x_offset)
{
	t_point	p1;
	t_point	p2;

	p1.i = i;
	p1.j = j;
	p1.x_p = data->fdf.mtrx.node[i][j].x_p;
	p1.y_p = data->fdf.mtrx.node[i][j].y_p;
	if (direct == 1)
	{
		p2.i = i;
		p2.j = j + 1;
		p2.x_p = data->fdf.mtrx.node[i][j + 1].x_p;
		p2.y_p = data->fdf.mtrx.node[i][j + 1].y_p;
	}
	else
	{
		p2.i = i + 1;
		p2.j = j;
		p2.x_p = data->fdf.mtrx.node[i + 1][j].x_p;
		p2.y_p = data->fdf.mtrx.node[i + 1][j].y_p;
	}
	bresenhams(data, p1, p2, x_offset);
}

int	create_rgb2(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_set_colors_sep(t_fdf *data, t_point *p1)
{
	int	num;

	data->param.color += 1;
	if (data->mtrx.node[p1->i][p1->j].color != -1)
		p1->color = data->mtrx.node[p1->i][p1->j].color;
	else
	{
		if (data->mtrx.z_max - data->mtrx.z_min == 0)
			num = 255;
		else
			num = (float)(data->mtrx.node[p1->i][p1->j].z - data->mtrx.z_min)
				/ (float)(data->mtrx.z_max - data->mtrx.z_min) * 255;
		// if (data->param.color % 3 == 1 && num < 0.5 * 255)
		// 	p1->color = create_rgb2(255, num * 2, 0);
		// else if (data->param.color % 3 == 1 && num >= 0.5 * 255)
		// 	p1->color = create_rgb2(255, 255, num);
		// else if (data->param.color % 3 == 2 && num < 0.5 * 255)
		// 	p1->color = create_rgb2(num * 2, 0, 255);
		// else if (data->param.color % 3 == 2 && num >= 0.5 * 255)
		// 	p1->color = create_rgb2(255, num, 255);
		// else if (data->param.color % 3 == 0 && num < 0.5 * 255)
		// 	p1->color = create_rgb2(0, 255, num * 2);
		// else
		// 	p1->color = create_rgb2(num, 255, 255);
		if (data->param.color % 3 == 1)
			p1->color = create_rgb2(num, 255, 255);
	}
	if (data->mtrx.node[p1->i][p1->j].z == data->mtrx.z_max)
		p1->color = create_rgb2(255, 0, 0);
	else
		p1->color = create_rgb2(255, 255, 255);
}

void	ft_set_colors(t_fdf *data, t_point *p1, t_point *p2)
{
	ft_set_colors_sep(data, p1);
	ft_set_colors_sep(data, p2);
}

int	ft_color(t_point p1, t_point p2, t_point p)
{
	int		color;
	float	ratio;

	if (p2.x_p - p1.x_p == 0 && p2.y_p - p1.y_p == 0)
		ratio = 1.0;
	else if (p2.x_p - p1.x_p == 0)
		ratio = (float)(p.y_p - p1.y_p) / (p2.y_p - p1.y_p);
	else
		ratio = (float)(p.x_p - p1.x_p) / (p2.x_p - p1.x_p);
	color = (p2.color - p1.color) * ratio + p1.color;
	return (color);
}

void	bresenhams(t_data *data, t_point p1, t_point p2, int x_offset)
{
	t_point	p;
	int		err;
	int		e;

	p.x_p = p1.x_p;
	p.y_p = p1.y_p;
	err = ft_abs(p2.x_p, p1.x_p) - ft_abs(p2.y_p, p1.y_p);
	ft_set_colors(&data->fdf, &p1, &p2);
	while (p.x_p != p2.x_p || p.y_p != p2.y_p)
	{
		// ft_pixel(data, p.x_p, p.y_p, ft_color(p1, p2, p));
        ft_pixel(data, p.x_p, p.y_p, ft_color(p1, p2, p), x_offset);
		e = 2 * err;
		if (e > -1 * ft_abs(p2.y_p, p1.y_p))
		{
			err -= ft_abs(p2.y_p, p1.y_p);
			p.x_p += ft_slope(p1.x_p, p2.x_p);
		}
		if (e < ft_abs(p2.x_p, p1.x_p))
		{
			err += ft_abs(p2.x_p, p1.x_p);
			p.y_p += ft_slope(p1.y_p, p2.y_p);
		}
	}
	// ft_pixel(data, p.x_p, p.y_p, ft_color(p1, p2, p));
    ft_pixel(data, p.x_p, p.y_p, ft_color(p1, p2, p), x_offset);
}

void	ft_pixel(t_data *data, int x, int y, int color, int x_offset)
{
	char	*pixel;
	int		i;
    
    x = x + x_offset;
    y = y + WINDOW_HEIGHT / 2;
	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return ;
	if (data->fdf.length > data->rays[x - 1])
		return ;
	i = data->img_win.bpp - 8;
	pixel = data->img_win.addr + (y * data->img_win.line_len + x * (data->img_win.bpp / 8));
	while (i >= 0)
	{
		if (data->img_win.endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (data->img_win.bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	ft_abs(int a, int b)
{
	if (a - b < 0)
		return (b - a);
	else
		return (a - b);
}

int	ft_slope(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}







/*  -----------------------------------------------------------------------------   */
                            /*  Setting the parameters  */
/*  -----------------------------------------------------------------------------   */
int	ft_find_grid(t_fdf *my_data, int width)
{
	double	returner;
	double	max;
	double		offset;

	offset = my_data->param.x_offset;
	max = my_data->mtrx.height;
	if (max < my_data->mtrx.width)
		max = my_data->mtrx.width;
	returner = (double)width / 2 / max;
	while (returner < 2 && offset > 120)
	{
		offset = offset / 2;
		returner = ((double)width - 2.0 * offset) / max;
	}
	return (returner);
}

int	ft_find_attitude(t_fdf *my_data, int height)
{
	double	returner;
	double		offset;

	offset = my_data->param.y_offset;
	returner = (double)height / 4;
	returner /= my_data->mtrx.z_max - my_data->mtrx.z_min;
	while (returner < 2 && offset > 70)
	{
		offset = offset / 2;
		returner = ((double)height - 2.0 * offset);
		returner /= (my_data->mtrx.z_max - my_data->mtrx.z_min);
	}
	return (returner);
}

double calculate_angle(double x, double y) {
    // Calculate the angle in radians using arctan2 function
    double angle = atan2(y, x);

    // Convert the angle from radians to degrees
    double angleDegrees = angle * (180.0 / PI);

    // Ensure the angle is positive
    if (angleDegrees < 0) {
        angleDegrees += 360.0;
    }

    return angleDegrees;
}

void	ft_set_params(t_data *my_data, int width, int height)
{
	// printf("%lf\n", my_data->fdf.pos_p.y);
	my_data->fdf.param.alpha = 90 - 40 * (1.0 / fabs(my_data->fdf.pos_p.y));
	// my_data->fdf.param.alpha = 50;
	my_data->fdf.param.beta = 180;
	// printf("Degree: %lf, Pos: %lf and %lf\n", atan(my_data->fdf.pos.y / my_data->fdf.pos.x), my_data->fdf.pos.x, my_data->fdf.pos.y);
	my_data->fdf.param.theta = calculate_angle(my_data->fdf.pos.x, my_data->fdf.pos.y);
	// printf("My degree is %d, Pos: %lf and %lf\n", my_data->fdf.param.theta, my_data->fdf.pos.x, my_data->fdf.pos.y);
	if (my_data->fdf.param.theta < 0)
		my_data->fdf.param.theta += 360;
	if (my_data->fdf.param.theta >= 360)
		my_data->fdf.param.theta -= 360;
	my_data->fdf.param.x_offset = width / 2;
	my_data->fdf.param.y_offset = height / 2;
	my_data->fdf.param.grid = ft_find_grid(&my_data->fdf, width) * 3;
	my_data->fdf.param.attitude = ft_find_attitude(&my_data->fdf, height) * 2;
}

