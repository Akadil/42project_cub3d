/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   react_to_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:53:04 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/18 21:20:46 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include <stdio.h>

void	ft_move_forward(t_data *data);
void	ft_move_backward(t_data *data);
void	ft_move_right(t_data *data);
void	ft_move_left(t_data *data);
void    ft_rotate_right(t_data *data);
void    ft_rotate_left(t_data *data);

void	ft_react_to_event(t_data *data)
{
	if (data->event.move_fw == true)
		ft_move_forward(data);
	if (data->event.move_bw == true)
		ft_move_backward(data);
	if (data->event.move_rg == true)
		ft_move_right(data);
	if (data->event.move_lf == true)
		ft_move_left(data);
	if (data->event.rotate_lf == true)
		ft_rotate_left(data);
	if (data->event.rotate_rg == true)
		ft_rotate_right(data);
	if (data->event.rotate_rg_mouse > 0)
	{
		data->event.rotation_speed = data->event.rotate_rg_mouse;
		ft_rotate_right(data);
		data->event.rotation_speed = 3;
		data->event.rotate_rg_mouse = 0;
	}
	if (data->event.rotate_lf_mouse > 0)
	{
		data->event.rotation_speed = data->event.rotate_lf_mouse;
		ft_rotate_left(data);
		data->event.rotation_speed = 3;
		data->event.rotate_lf_mouse = 0;
	}
}
