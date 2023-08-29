/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:37:14 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/29 17:06:05 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "struct_data.h"
#include <X11/X.h>
#include <X11/keysym.h>
#include <stdbool.h>
#include <stdio.h>

int	ft_key_press(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	else if (keysym == 'w')
		data->event.move_fw = true;
	else if (keysym == 's')
		data->event.move_bw = true;
	else if (keysym == 'a')
		data->event.move_lf = true;
	else if (keysym == 'd')
		data->event.move_rg = true;
	else if (keysym == 65361)
		data->event.rotate_lf = true;
	else if (keysym == 65363)
		data->event.rotate_rg = true;
	return (0);
}

int	ft_key_release(int keysym, t_data *data)
{
	if (keysym == 'w')
		data->event.move_fw = false;
	if (keysym == 's')
		data->event.move_bw = false;
	if (keysym == 'a')
		data->event.move_lf = false;
	if (keysym == 'd')
		data->event.move_rg = false;
	if (keysym == 65361)
		data->event.rotate_lf = false;
	if (keysym == 65363)
		data->event.rotate_rg = false;
	return (0);
}

int	ft_mouse_move(int x, int y, t_data *data)
{
	(void)y;
	if (x != WINDOW_WIDTH / 2)
	{
		if (x - WINDOW_WIDTH / 2 > 0)
			data->event.rotate_rg_mouse = (double)(x - WINDOW_WIDTH / 2)
				/ (WINDOW_WIDTH / 2) * 33;
		else
			data->event.rotate_lf_mouse = (double)(WINDOW_WIDTH / 2 - x)
				/ (WINDOW_WIDTH / 2) * 33;
		mlx_mouse_move(data->mlx_ptr, data->win_ptr, WINDOW_WIDTH / 2,
			WINDOW_HEIGHT / 2);
	}
	return (0);
}
