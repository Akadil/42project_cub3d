/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_colors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:08:40 by aseisenb          #+#    #+#             */
/*   Updated: 2023/08/30 14:45:03 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering_utils.h"

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

double	ft_calculate_the_ratio(t_draw *draw, int i)
{
	double	result;

	result = (double)(2 * (draw->draw_start + i) + draw->line_height - WINDOW_HEIGHT);
	result = result / 2 / draw->line_height;
	return (result);
}
