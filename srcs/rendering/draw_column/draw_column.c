/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:23:47 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/26 16:36:49 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "struct_ray.h"
#include <stdio.h>

typedef struct s_draw
{
    int     lineHeight;
    int     draw_start;
    int     draw_end;

    float   ratio_x;
    float   ratio_y;
    int     pos_x;
    int     pos_y;

    int     x;
    int     pos_color;
    int     r;
    int     g;
    int     b;
}   		t_draw;

void	ft_get_the_colors_west(t_data *data, t_draw *draw);
void	ft_get_the_colors_east(t_data *data, t_draw *draw);
void	ft_get_the_colors_north(t_data *data, t_draw *draw);
void	ft_get_the_colors_south(t_data *data, t_draw *draw);
double	ft_calculate_the_ratio(t_draw *draw, int i);
void	ft_draw_column_east(t_data *data, t_ray *ray, t_draw *draw);
void	ft_draw_column_west(t_data *data, t_ray *ray, t_draw *draw);
void	ft_draw_column_south(t_data *data, t_ray *ray, t_draw *draw);
void	ft_draw_column_north(t_data *data, t_ray *ray, t_draw *draw);
int     create_rgb(int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

void    ft_draw_column(t_data *data, t_ray *ray, int x)
{
    t_draw  draw;

    draw.lineHeight = (int)(WINDOW_HEIGHT / ray->distance_perp);
    draw.draw_start = -1 * draw.lineHeight / 2 + WINDOW_HEIGHT / 2;
    if (draw.draw_start < 0)
        draw.draw_start = 0;
    draw.draw_end = draw.lineHeight / 2 + WINDOW_HEIGHT / 2;
    if (draw.draw_end >= WINDOW_HEIGHT)
        draw.draw_end = WINDOW_HEIGHT - 1;
    draw.x = x;
    if (ray->side == 1 && ray->dir.y > 0)
        ft_draw_column_south(data, ray, &draw);
    else if (ray->side == 1 && ray->dir.y <= 0)
        ft_draw_column_north(data, ray, &draw);      // Ths
    else if (ray->side == 0 && ray->dir.x > 0)
        ft_draw_column_west(data, ray, &draw);
    else
        ft_draw_column_east(data, ray, &draw);
}

void	ft_draw_column_north(t_data *data, t_ray *ray, t_draw *draw)
{
    int             i;
	int				color_hex;

    i = 0;
	draw->ratio_x = data->player.x + ray->distance_perp * ray->dir.x;
	draw->ratio_x -= (int)draw->ratio_x;
	draw->pos_x = (double)data->wall.north.width * draw->ratio_x;
    //printf("----------------------------------------\n");
	while (draw->draw_start + i < draw->draw_end)
    {
		draw->ratio_y = ft_calculate_the_ratio(draw, i);
		draw->pos_y = (int)(data->wall.north.height * draw->ratio_y);
		ft_get_the_colors_north(data, draw);
		color_hex = create_rgb(draw->r, draw->g, draw->b);
		my_mlx_pixel_put(data, draw->x, draw->draw_start + i, color_hex); 
		i++;
        //printf("%f\n", draw->ratio_y);
    }
    //printf("----------------------------------------\n");
}

void	ft_draw_column_south(t_data *data, t_ray *ray, t_draw *draw)
{
    int             i;
	int				color_hex;

    i = 0;
	draw->ratio_x = data->player.x + ray->distance_perp * ray->dir.x;
	draw->ratio_x -= (int)draw->ratio_x;
	draw->pos_x = (double)data->wall.south.width * draw->ratio_x;
	while (draw->draw_start + i < draw->draw_end)
    {
		draw->ratio_y = ft_calculate_the_ratio(draw, i);
		draw->pos_y = (int)(data->wall.south.height * draw->ratio_y);
		ft_get_the_colors_south(data, draw);
		color_hex = create_rgb(draw->r, draw->g, draw->b);
		my_mlx_pixel_put(data, draw->x, draw->draw_start + i, color_hex); 
		i++;
	}
}

void	ft_draw_column_west(t_data *data, t_ray *ray, t_draw *draw)
{
    int             i;
	int				color_hex;

    i = 0;
	draw->ratio_x = data->player.y + ray->distance_perp * ray->dir.y;
	draw->ratio_x -= (int)draw->ratio_x;
	draw->pos_x = (double)data->wall.west.width * draw->ratio_x;
	while (draw->draw_start + i < draw->draw_end)
    {
		draw->ratio_y = ft_calculate_the_ratio(draw, i);
		draw->pos_y = (int)(data->wall.west.height * draw->ratio_y);
		ft_get_the_colors_west(data, draw);
		color_hex = create_rgb(draw->r, draw->g, draw->b);
		my_mlx_pixel_put(data, draw->x, draw->draw_start + i, color_hex); 
		i++;
	}
}

void	ft_draw_column_east(t_data *data, t_ray *ray, t_draw *draw)
{
    int             i;
	int				color_hex;

    i = 0;
	draw->ratio_x = data->player.y + ray->distance_perp * ray->dir.y;
	draw->ratio_x -= (int)draw->ratio_x;
	draw->pos_x = (double)data->wall.east.width * draw->ratio_x;
	while (draw->draw_start + i < draw->draw_end)
    {
		draw->ratio_y = ft_calculate_the_ratio(draw, i);
		draw->pos_y = (int)(data->wall.east.height * draw->ratio_y);
		ft_get_the_colors_east(data, draw);
		color_hex = create_rgb(draw->r, draw->g, draw->b);
		my_mlx_pixel_put(data, draw->x, draw->draw_start + i, color_hex); 
		i++;
	}
}

/*  Approved    */
double	ft_calculate_the_ratio(t_draw *draw, int i)
{
	double	result;

	result = (double)(2 * (draw->draw_start + i) + draw->lineHeight - WINDOW_HEIGHT);
	result = result / 2 / draw->lineHeight;
	return (result);
}

void	ft_get_the_colors_north(t_data *data, t_draw *draw)
{
	int		pos_of_color;
	double	pos_of_color_x;
	double	pos_of_color_y;

    // printf("%d, %d\n", draw->pos_y, draw->pos_x);
	pos_of_color_y = draw->pos_y * data->wall.north.line_len;
	pos_of_color_x = (double)draw->pos_x * data->wall.north.bpp / 8;
	pos_of_color = (int)(pos_of_color_x + pos_of_color_y);
	// printf("%d\n", pos_of_color);
    draw->r = data->wall.north.addr[pos_of_color];
	draw->g = data->wall.north.addr[pos_of_color + 1];
	draw->b = data->wall.north.addr[pos_of_color + 2];
    // printf("%d, %d, %d\n", draw->r, draw->g, draw->b);
}

void	ft_get_the_colors_south(t_data *data, t_draw *draw)
{
	int		pos_of_color;
	double	pos_of_color_x;
	double	pos_of_color_y;

	pos_of_color_y = draw->pos_y * data->wall.south.line_len;
	pos_of_color_x = (double)draw->pos_x * data->wall.south.bpp / 8;
	pos_of_color = (double)(pos_of_color_x + pos_of_color_y);
	draw->r = data->wall.south.addr[pos_of_color];
	draw->g = data->wall.south.addr[pos_of_color + 1];
	draw->b = data->wall.south.addr[pos_of_color + 2];
}

void	ft_get_the_colors_east(t_data *data, t_draw *draw)
{
	int		pos_of_color;
	double	pos_of_color_x;
	double	pos_of_color_y;

	pos_of_color_y = draw->pos_y * data->wall.east.line_len;
	pos_of_color_x = (double)draw->pos_x * data->wall.east.bpp / 8;
	pos_of_color = (double)(pos_of_color_x + pos_of_color_y);
	draw->r = data->wall.east.addr[pos_of_color];
	draw->g = data->wall.east.addr[pos_of_color + 1];
	draw->b = data->wall.east.addr[pos_of_color + 2];
}

void	ft_get_the_colors_west(t_data *data, t_draw *draw)
{
	int		pos_of_color;
	double	pos_of_color_x;
	double	pos_of_color_y;

	pos_of_color_y = draw->pos_y * data->wall.west.line_len;
	pos_of_color_x = (double)draw->pos_x * data->wall.west.bpp / 8;
	pos_of_color = (double)(pos_of_color_x + pos_of_color_y);
	draw->r = data->wall.west.addr[pos_of_color];
	draw->g = data->wall.west.addr[pos_of_color + 1];
	draw->b = data->wall.west.addr[pos_of_color + 2];
}