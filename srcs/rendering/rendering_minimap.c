/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:10:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/30 16:03:20 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rendering_utils.h"
#include "struct_data.h"
#include <math.h>
#include <stdio.h>

void	bresenhams2(t_data *data, t_vector *p1, t_vector *p2)
{
	t_vector	p;
	int			err;
	int			e;

	p.x = (int)p1->x;
	p.y = (int)p1->y;
	err = ft_abs2((int)p2->x, (int)p1->x) - ft_abs2((int)p2->y, (int)p1->y);
	while ((int)p.x != (int)p2->x || (int)p.y != (int)p2->y)
	{
		my_mlx_pixel_put(data, (int)p.x, (int)p.y, create_rgb(255, 255, 255));
		e = 2 * err;
		if (e > -1 * ft_abs2((int)p2->y, (int)p1->y))
		{
			err -= ft_abs2((int)p2->y, (int)p1->y);
			p.x += ft_slope2((int)p1->x, (int)p2->x);
		}
		if (e < ft_abs2((int)p2->x, (int)p1->x))
		{
			err += ft_abs2((int)p2->x, (int)p1->x);
			p.y += ft_slope2((int)p1->y, (int)p2->y);
		}
	}
	my_mlx_pixel_put(data, (int)p.x, (int)p.y, create_rgb(255, 255, 255));
}

void	ft_many_bresenhams(t_data *data, t_vector map_ray, t_vector *player);

typedef struct s_draw_p
{
	int	i_beg;
	int	i_end;
	int	j_beg;
	int	j_end;
}		t_draw_p;

void	ft_draw_player(t_data *data)
{
	t_vector	map_ray;
	t_vector	player;
	t_draw		draw;

	map_ray.x = 0.0;
	map_ray.y = 0.0;
	draw.i_beg = (double)WINDOW_HEIGHT / 4.0 * 3.0 + data->player.y * 5.0 - 1;
	draw.i_end = (double)WINDOW_HEIGHT / 4.0 * 3 + data->player.y * 5.0 + 1;
	while (draw.i_beg < draw.i_end)
	{
		draw.j_beg = (double)WINDOW_WIDTH / 4.0 * 3.0 + data->player.x * 5.0
			- 1;
		draw.j_end = (double)WINDOW_WIDTH / 4.0 * 3.0 + data->player.x * 5.0
			+ 1;
		while (draw.j_beg < draw.j_end)
		{
			my_mlx_pixel_put(data, draw.j_beg, draw.i_beg, create_rgb(0, 255,
					0));
			draw.j_beg++;
		}
		draw.i_beg++;
	}
	player.y = (double)WINDOW_HEIGHT / 4.0 * 3.0 + data->player.y * 5.0;
	player.x = (double)WINDOW_WIDTH / 4.0 * 3.0 + data->player.x * 5.0;
	ft_many_bresenhams(data, map_ray, &player);
}

void	ft_many_bresenhams(t_data *data, t_vector map_ray, t_vector *player)
{
	map_ray.x = player->x + data->view.dir.x * 5 * data->rays[WINDOW_WIDTH / 2];
	map_ray.y = player->y + data->view.dir.y * 5 * data->rays[WINDOW_WIDTH / 2];
	bresenhams2(data, player, &map_ray);
	map_ray.x = player->x + (data->view.dir.x * 5 + data->view.plane.x * 3)
		* data->rays[WINDOW_WIDTH - 1];
	map_ray.y = player->y + (data->view.dir.y * 5 + data->view.plane.y * 3)
		* data->rays[WINDOW_WIDTH - 1];
	bresenhams2(data, player, &map_ray);
	map_ray.x = player->x + (data->view.dir.x * 5 - data->view.plane.x * 3)
		* data->rays[0];
	map_ray.y = player->y + (data->view.dir.y * 5 - data->view.plane.y * 3)
		* data->rays[0];
	bresenhams2(data, player, &map_ray);
	map_ray.x = player->x + (data->view.dir.x * 5 + data->view.plane.x * 1.5)
		* data->rays[WINDOW_WIDTH / 4 * 3];
	map_ray.y = player->y + (data->view.dir.y * 5 + data->view.plane.y * 1.5)
		* data->rays[WINDOW_WIDTH / 4 * 3];
	bresenhams2(data, player, &map_ray);
	map_ray.x = player->x + (data->view.dir.x * 5 - data->view.plane.x * 1.5)
		* data->rays[WINDOW_WIDTH / 4];
	map_ray.y = player->y + (data->view.dir.y * 5 - data->view.plane.y * 1.5)
		* data->rays[WINDOW_WIDTH / 4];
	bresenhams2(data, player, &map_ray);
}

void	ft_rendering_minimap(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (data->map[x])
	{
		y = 0;
		while (data->map[x][y])
		{
			if (data->map[x][y] == '0' || data->map[x][y] == 'N'
				|| data->map[x][y] == 'S' || data->map[x][y] == 'E'
				|| data->map[x][y] == 'W')
				ft_draw_rectangle(data, x, y, create_rgb(0, 0, 255));
			y++;
		}
		x++;
	}
	ft_draw_player(data);
}
