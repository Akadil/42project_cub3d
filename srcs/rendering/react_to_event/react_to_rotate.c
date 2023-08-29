/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   react_to_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 15:19:08 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/29 18:39:26 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering_utils.h"
#define PI 3.14

void	ft_rotate_right(t_data *data)
{
	data->angle += ROTATION * data->event.rotation_speed;
	if (data->angle >= 360)
		data->angle -= 360;
	ft_set_direction_vector(data->angle, &data->view);
}

void	ft_rotate_left(t_data *data)
{
	data->angle -= ROTATION * data->event.rotation_speed;
	if (data->angle < 0)
		data->angle += 360;
	ft_set_direction_vector(data->angle, &data->view);
}

void	ft_set_direction_vector(float angle, t_view *view)
{
	view->dir.x = cos(angle * PI / 180);
	view->dir.y = sin(angle * PI / 180);
	view->plane.x = 0.66 * sin(angle * PI / 180) * -1;
	view->plane.y = 0.66 * cos(angle * PI / 180);
}
