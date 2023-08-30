/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_column.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 16:23:47 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/30 15:41:05 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering_utils.h"

void	ft_draw_column(t_data *data, t_ray *ray, int x)
{
	t_draw	draw;

	draw.line_height = (int)(WINDOW_HEIGHT / ray->distance_perp);
	draw.draw_start = -1 * draw.line_height / 2 + WINDOW_HEIGHT / 2;
	if (draw.draw_start < 0)
		draw.draw_start = 0;
	draw.draw_end = draw.line_height / 2 + WINDOW_HEIGHT / 2;
	if (draw.draw_end >= WINDOW_HEIGHT)
		draw.draw_end = WINDOW_HEIGHT - 1;
	draw.x = x;
	if (ray->side == 1 && ray->dir.y > 0)
		ft_draw_column_south(data, ray, &draw);
	else if (ray->side == 1 && ray->dir.y <= 0)
		ft_draw_column_north(data, ray, &draw);
	else if (ray->side == 0 && ray->dir.x > 0)
		ft_draw_column_west(data, ray, &draw);
	else
		ft_draw_column_east(data, ray, &draw);
}

void	ft_draw_column_north(t_data *data, t_ray *ray, t_draw *draw)
{
	int	i;
	int	color_hex;

	i = 0;
	draw->ratio_x = data->player.x + ray->distance_perp * ray->dir.x;
	draw->ratio_x -= (int)draw->ratio_x;
	draw->pos_x = (double)data->wall.north.width * draw->ratio_x;
	while (draw->draw_start + i < draw->draw_end)
	{
		draw->ratio_y = ft_calculate_the_ratio(draw, i);
		draw->pos_y = (int)(data->wall.north.height * draw->ratio_y);
		ft_get_the_colors_north(data, draw);
		color_hex = create_rgb(draw->r, draw->g, draw->b);
		my_mlx_pixel_put(data, draw->x, draw->draw_start + i, color_hex);
		i++;
	}
}

void	ft_draw_column_south(t_data *data, t_ray *ray, t_draw *draw)
{
	int	i;
	int	color_hex;

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
	int	i;
	int	color_hex;

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
	int	i;
	int	color_hex;

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
