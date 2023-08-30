/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_sprites.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 11:53:01 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/30 13:25:42 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rendering_utils.h"
#include "struct_data.h"
#include <stdio.h>
#include <stdlib.h>

void	ft_rendering_sprites(t_data *data)
{
	t_vector	sprite;
	t_vector	sprite_p;
	double		inv_det;
	int			screen_x;
	int			sprite_height;
	int			sprite_width;
	int			draw_start_y;
	int			draw_start_x;
	int			draw_end_x;
	int			draw_end_y;
	int			tex_x;
	int			tex_y;
	int			color;
	int			pos;
	int			y;

	/*  Sprite position */
	sprite.x = data->sprite_pos.x - data->player.x;
	sprite.y = data->sprite_pos.y - data->player.y;
	// printf("%lf %lf\n", data->player.x, data->player.y);
	/*  Determinant */
	inv_det = 1.0 / (data->view.plane.x * data->view.dir.y - data->view.plane.y
		* data->view.dir.x);
	/*  Transformed position    */
	sprite_p.x = inv_det * (data->view.dir.y * sprite.x - data->view.dir.x
		* sprite.y);
	sprite_p.y = inv_det * (-1 * data->view.plane.y * sprite.x
		+ data->view.plane.x * sprite.y);
	/*  Position in the screen  */
	screen_x = (double)WINDOW_WIDTH / 2 * (1.0 + sprite_p.x / sprite_p.y);
	sprite_height = abs((int)((double)WINDOW_HEIGHT / sprite_p.y));
	draw_start_y = -1.0 * (double)sprite_height / 2 + (double)(WINDOW_HEIGHT)
		/ 2;
	if (draw_start_y < 0)
		draw_start_y = 0;
	draw_end_y = (double)sprite_height / 2 + (double)(WINDOW_HEIGHT) / 2;
	if (draw_end_y >= WINDOW_HEIGHT)
		draw_end_y = WINDOW_HEIGHT - 1;
	sprite_width = abs((int)((double)WINDOW_HEIGHT / sprite_p.y));
	draw_start_x = -1.0 * sprite_width / 2 + screen_x;
	if (draw_start_x < 0)
		draw_start_x = 0;
	draw_end_x = sprite_width / 2 + screen_x;
	if (draw_end_x >= WINDOW_WIDTH)
		draw_end_x = WINDOW_WIDTH - 1;
	// int d;
	y = draw_start_y;
	while (draw_start_x < draw_end_x)
	{
		// printf("%lf\n", ray_distances[draw_start_x]);
		// tex_x = (int)(256 * (draw_start_x - (-1 * sprite_width / 2 + screen_x)) * data->sprite.width / sprite_width) / 256;
		tex_x = (double)(2 * draw_start_x + sprite_width - 2 * screen_x) / 2
			/ sprite_width * data->sprite.width;
		// printf("My tex_x is %d/%d\n", tex_x, data->sprite.width);
		if (sprite_p.y > 0 && draw_start_x > 0 && draw_start_x < WINDOW_WIDTH
			&& sprite_p.y < data->rays[draw_start_x])
		{
			draw_start_y = y;
			while (draw_start_y < draw_end_y)
			{
				tex_y = (2.0 * draw_start_y + sprite_height - WINDOW_HEIGHT) / 2
					/ sprite_height * data->sprite.height;
				pos = (double)tex_y * data->sprite.line_len + (double)tex_x
					* (float)data->sprite.bpp / 8;
				color = create_rgb((int)data->sprite.addr[pos],
					(int)data->sprite.addr[pos + 1], (int)data->sprite.addr[pos
					+ 2]);
				if (color != 0)
					my_mlx_pixel_put(data, draw_start_x, draw_start_y, color);
				draw_start_y++;
			}
		}
		draw_start_x++;
	}
}
