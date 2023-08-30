/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_3d_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:01:35 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/30 16:06:48 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rendering.h"

void	ft_rendering_3d_object(t_data *data)
{
	t_3d	object_3d;

	if (ft_set_3dobject_params(data, &object_3d) != 0)
		return ;
	ft_set_object_in_plane(data, &object_3d);
	ft_set_fdf_params(data, &object_3d);
	ft_render_3d(data, object_3d.draw_start_x);
}

void	ft_set_object_in_plane(t_data *data, t_3d *object_3d)
{
	int	sprite_height;
	int	sprite_width;

	(void)data;
	sprite_height = abs((int)((double)WINDOW_HEIGHT / object_3d->sprite_p.y));
	object_3d->draw_start_y = -1.0 * sprite_height / 2 + (double)(WINDOW_HEIGHT)
		/ 2;
	object_3d->draw_end_y = (double)sprite_height / 2 + (double)(WINDOW_HEIGHT)
		/ 2;
	sprite_width = abs((int)((double)WINDOW_HEIGHT / object_3d->sprite_p.y));
	object_3d->draw_start_x = -1.0 * sprite_width / 2 + object_3d->screen_x;
	object_3d->draw_end_x = sprite_width / 2 + object_3d->screen_x;
	object_3d->sprite_height = sprite_height;
	object_3d->sprite_width = sprite_width;
}

int	ft_set_3dobject_params(t_data *data, t_3d *object_3d)
{
	t_vector	sprite;
	t_vector	sprite_p;
	double		inv_det;
	int			screen_x;

	sprite.x = data->sprite_pos.x - data->player.x;
	sprite.y = data->sprite_pos.y - data->player.y;
	inv_det = 1.0 / (data->view.plane.x * data->view.dir.y - data->view.plane.y
			* data->view.dir.x);
	sprite_p.x = inv_det * (data->view.dir.y * sprite.x - data->view.dir.x
			* sprite.y);
	sprite_p.y = inv_det * (-1 * data->view.plane.y * sprite.x
			+ data->view.plane.x * sprite.y);
	if (sprite_p.y <= 1)
		return (-1);
	screen_x = (double)WINDOW_WIDTH / 2 * (1.0 + sprite_p.x / sprite_p.y);
	object_3d->sprite = sprite;
	object_3d->sprite_p = sprite_p;
	object_3d->inv_det = inv_det;
	object_3d->screen_x = screen_x;
	return (0);
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
				ft_draw_line_1(data, i, j, x_offset);
			if (i + 1 != data->fdf.mtrx.height)
				ft_draw_line_0(data, i, j, x_offset);
			j++;
		}
		i++;
	}
}
