/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:31:58 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/11 12:17:40 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

int    ft_rendering(t_data *data)
{
    if (data->win_ptr == NULL)
        return (1);
    ft_render_background(data, 0);

    ft_render_projection(data);
    // ft_render_hand(data);
    mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
                                data->img_win.mlx_img, 0, 0);
    // ft_render_minimap(data);
    // mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, 
    //                             data->img_minimap.mlx_img, 0, 0);
    return (0);
}
