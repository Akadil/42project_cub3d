/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:23:47 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/15 17:35:14 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "struct_ray.h"

typedef struct s_draw_windows
{
    int     y_height;
    int     y_start;
    int     y_end;
    int     x;
}   		t_draw_windows;

void    ft_draw_column(t_data *data, t_ray ray, int x)
{
    t_draw_windows  draw;

    draw.y_height = (int)(WINDOW_HEIGHT / ray.distance_perp);
    draw.y_start = -1 * draw.y_height / 2 + WINDOW_HEIGHT / 2;
    if (draw.y_start < 0)
        draw.y_start = 0;
    draw.y_end = draw.y_height / 2 + WINDOW_HEIGHT / 2;
    if (draw.y_end >= WINDOW_HEIGHT)
        draw.y_end = WINDOW_HEIGHT - 1;
    if (ray.side = 1 && ray.dir.y > 0)
        ft_draw_column_north(data, ray, &draw, x);
    else if (ray.side = 1 && ray.dir.y <= 0)
        ft_draw_column_south(data, ray, &draw, x);
    else if (ray.side = 1 && ray.dir.y > 0)
        ft_draw_column_north(data, ray, &draw, x);
    else
        ft_draw_column_north(data, ray, &draw, x);
}

typedef struct s_draw_image
{
    int     pos_x;
    int     pos_y;
    double  x_ratio;
    double  y_ratio;
    int     r;
    int     g;
    int     b;
}   		t_draw_image;

void	ft_draw_column_north(t_data *data, t_ray ray, t_draw_win draw_win)
{
	t_draw_image	img;
	t_color			color;
	int				color_hex;

	img.x_ratio = data->player.x + ray.distance_perp * ray.dir.x;
	img.x_ratio -= (int)img.x_ratio;
	img.pos_x = (double)data->wall.south.width * img.x_ratio;
	while (draw_win.y_start < draw_win.y_end)
    {
		img.y_ratio = ft_calculate_the_ratio(draw_win);
		img.pos_y = (int)(data->wall.north.height * img.y_ratio);
		ft_get_the_colors(data, img, color);
		color_hex = create_rgb(color.r, color.g, color.b);
		my_mlx_pixel_put(data, x, draw_win.y_start, color_hex); 
		draw_win.y_start++;
	}
}

double	ft_calculate_the_ratio(t_draw_windows draw_win)
{
	double	result;

	result = (float)(2 * draw_win.y_start + draw_win.y_height - WINDOW_HEIGHT);
	result = result / 2 / draw_win.y_height;
	return (result);
}

void	ft_get_the_colors(t_data *data, t_draw_image img, t_color color)
{
	int		pos_of_color;
	double	pos_of_color_x;
	double	pos_of_color_y;

	pos_of_color_y = img.pos_y * data->wall.north.line_len;
	pos_of_color_x = (double)img.pos_x * data->wall.north.bpp / 8;
	pos_of_color = (double)(pos_of_color_x + pos_of_color_y);
	color.r = data->wall.north.addr[pos_of_color];
	color.g = data->wall.north.addr[pos_of_color + 1];
	color.b = data->wall.north.addr[pos_of_color + 2];
}