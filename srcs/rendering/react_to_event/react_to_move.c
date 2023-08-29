/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   react_to_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:17:41 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/29 18:37:48 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include <math.h>

void	ft_move_forward(t_data *data)
{
	int		x_pos;
	int		y_pos;
	double	x_pos_new;
	double	y_pos_new;

	x_pos = (int)(data->player.x);
	y_pos = (int)(data->player.y);
	x_pos_new = data->player.x + data->view.dir.x * SPEED;
	if (data->map[y_pos][(int)(x_pos_new)] != '1' /*
		&& data->map[y_pos][(int)ceil(x_pos_new)] != '1'*/)
		data->player.x = x_pos_new;
	y_pos_new = data->player.y + data->view.dir.y * SPEED;
	if (data->map[(int)(y_pos_new)][x_pos] != '1' /*
		&& data->map[(int)ceil(y_pos_new)][x_pos] != '1'*/)
		data->player.y = y_pos_new;
}

void	ft_move_backward(t_data *data)
{
	int		x_pos;
	int		y_pos;
	double	x_pos_new;
	double	y_pos_new;

	x_pos = (int)(data->player.x);
	y_pos = (int)(data->player.y);
	x_pos_new = data->player.x - data->view.dir.x * SPEED;
	if (data->map[y_pos][(int)(x_pos_new)] != '1')
		data->player.x = x_pos_new;
	y_pos_new = data->player.y - data->view.dir.y * SPEED;
	if (data->map[(int)(y_pos_new)][x_pos] != '1')
		data->player.y = y_pos_new;
}

void	ft_move_left(t_data *data)
{
	int		x_pos;
	int		y_pos;
	double	x_pos_new;
	double	y_pos_new;

	x_pos = (int)(data->player.x);
	y_pos = (int)(data->player.y);
	x_pos_new = data->player.x - data->view.plane.x * SPEED;
	if (data->map[y_pos][(int)(x_pos_new)] != '1')
		data->player.x = x_pos_new;
	y_pos_new = data->player.y - data->view.plane.y * SPEED;
	if (data->map[(int)(y_pos_new)][x_pos] != '1')
		data->player.y = y_pos_new;
}

void	ft_move_right(t_data *data)
{
	int		x_pos;
	int		y_pos;
	double	x_pos_new;
	double	y_pos_new;

	x_pos = (int)(data->player.x);
	y_pos = (int)(data->player.y);
	x_pos_new = data->player.x + data->view.plane.x * SPEED;
	if (data->map[y_pos][(int)(x_pos_new)] != '1')
		data->player.x = x_pos_new;
	y_pos_new = data->player.y + data->view.plane.y * SPEED;
	if (data->map[(int)(y_pos_new)][x_pos] != '1')
		data->player.y = y_pos_new;
}
