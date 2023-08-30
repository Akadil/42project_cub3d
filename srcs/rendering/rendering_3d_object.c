/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_3d_object.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 11:01:35 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/30 13:43:54 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rendering.h"

void	ft_rendering_3d_object(t_data *data)
{
	t_3d		object_3d;

	if (ft_set_3dobject_params(data, &object_3d) != 0)
		return ;
	ft_set_object_in_plane(data, &object_3d);
	ft_set_fdf_params(data, &object_3d);
	ft_render_3d(data, object_3d.draw_start_x);
}

void	ft_set_object_in_plane(t_data *data, t_3d *object_3d)
{
	int			sprite_height;
	int			sprite_width;

	(void)data;
	sprite_height = abs((int)((double)WINDOW_HEIGHT / object_3d->sprite_p.y));
	object_3d->draw_start_y = -1.0 * sprite_height / 2 + (double)(WINDOW_HEIGHT) / 2;
	object_3d->draw_end_y = (double)sprite_height / 2 + (double)(WINDOW_HEIGHT) / 2;
	sprite_width = abs((int)((double)WINDOW_HEIGHT / object_3d->sprite_p.y));
	object_3d->draw_start_x = -1.0 * sprite_width / 2 + object_3d->screen_x;
	object_3d->draw_end_x = sprite_width / 2 + object_3d->screen_x;
	object_3d->sprite_height = sprite_height;
	object_3d->sprite_width = sprite_width;
}

int		ft_set_3dobject_params(t_data *data, t_3d *object_3d)
{
	t_vector	sprite;
	t_vector	sprite_p;
	double		inv_det;
	int			screen_x;

	sprite.x = data->sprite_pos.x - data->player.x;
	sprite.y = data->sprite_pos.y - data->player.y;
	inv_det = 1.0 / (data->view.plane.x * data->view.dir.y - data->view.plane.y * data->view.dir.x);
	sprite_p.x = inv_det * (data->view.dir.y * sprite.x - data->view.dir.x * sprite.y);
	sprite_p.y = inv_det * (-1 * data->view.plane.y * sprite.x + data->view.plane.x * sprite.y);
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
	double	x;
	double	y;
	double	z;

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
	y_p += x * cos(ft_rad(data->param.theta)) * sin(ft_rad(data->param.beta)) * sin(ft_rad(data->param.alpha));
	y_p -= y * sin(ft_rad(data->param.theta)) * sin(ft_rad(data->param.beta)) * sin(ft_rad(data->param.alpha));
	y_p += z * cos(ft_rad(data->param.beta)) * sin(ft_rad(data->param.alpha));
	y_p += data->param.y_offset;
	data->mtrx.node[i][j].x_p = (int)x_p;
	data->mtrx.node[i][j].y_p = (int)y_p;
}

float	ft_rad(int angle)
{
	return (angle * (3.142857 / 180.0));
}
