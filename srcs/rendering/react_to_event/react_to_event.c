/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   react_to_event.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 14:53:04 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/11 15:31:24 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"

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
}
