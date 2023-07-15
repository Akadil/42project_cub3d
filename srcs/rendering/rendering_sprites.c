/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:53:01 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/13 15:46:12 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include <stdlib.h>

void    ft_rendering_sprites(t_data *data, double ray_distances[WINDOW_WIDTH])
{
    t_vector    sprite;
    t_vector    sprite_p;
    double      inv_det;
    int         screen_x;
    int         sprite_height;
    int         sprite_width;
    int         draw_start_y;
    int         draw_start_x;
    int         draw_end_x;
    int         draw_end_y;         

    sprite.x = 8.5;
    sprite.y = 27.5;
    inv_det = 1.0 / (data->view.plane.x * data->view.dir.y - data->view.plane.y * data->view.dir.x);
    sprite_p.x = inv_det * (data->view.dir.y * sprite.x - data->view.dir.x * sprite.y);
    sprite_p.y = inv_det * (-1 * data->view.plane.y * sprite.x - data->view.plane.x * sprite.y);
    screen_x = (int)((double)(WINDOW_WIDTH) / 2 * (1.0 + sprite_p.x / sprite_p.y));

    sprite_height = abs ((int)((double)WINDOW_HEIGHT / sprite_p.y));
    draw_start_y = -1.0 * (double)sprite_height / 2 + (double)(WINDOW_HEIGHT) / 2;
    if(draw_start_y < 0) 
        draw_start_y = 0;
    draw_end_y = (double)sprite_height / 2 + (double)(WINDOW_HEIGHT) / 2;
    if(draw_end_y >= WINDOW_HEIGHT)
        draw_end_y = WINDOW_HEIGHT - 1;

    sprite_width = abs( (int) ((double)WINDOW_HEIGHT / sprite_p.y));
    draw_start_x = -1.0 * sprite_width / 2 + screen_x;
    if(draw_start_x < 0)
        draw_start_x = 0;
    draw_end_x = sprite_width / 2 + screen_x;
    if(draw_end_x >= WINDOW_WIDTH)
        draw_end_x = WINDOW_WIDTH - 1;

    
}