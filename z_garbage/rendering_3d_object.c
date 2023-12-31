/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_3d_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:01:35 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/29 19:01:55 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rendering.h"

void	ft_rendering_3d_object(t_data *data)
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
	if (sprite_p.y <= 1)
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
    // if (draw_start_y < 0) 
    //     draw_start_y = 0;
    // if (draw_end_y >= WINDOW_HEIGHT)
    //     draw_end_y = WINDOW_HEIGHT - 1;
    // if (draw_start_x < 0)
    //     draw_start_x = 0;
    // if (draw_end_x >= WINDOW_WIDTH)
	// 	draw_end_x = WINDOW_WIDTH - 1;
    data->fdf.length = sprite_p.y;
	data->fdf.pos.x = sprite.x;
	data->fdf.pos.y = sprite.y;
	data->fdf.pos_p.x = sprite_p.x;
	data->fdf.pos_p.y = sprite_p.y;
	// printf("1. %lf of %lf\n", data->fdf.pos_p.y, sprite_p.y);
	// I think I have to pass the draw_start !
    ft_render_3d(data, draw_start_x);
}

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
