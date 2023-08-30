/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:31:58 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/30 17:13:02 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

int	ft_rendering(t_data *data)
{
	if (data->win_ptr == NULL)
		return (1);
	ft_react_to_event(data);
	ft_render_background(data, 0);
	ft_render_projection(data);
	ft_rendering_3d_object(data);
	ft_rendering_minimap(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_win.mlx_img,
		0, 0);
	return (0);
}
