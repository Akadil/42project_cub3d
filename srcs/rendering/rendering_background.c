/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_background.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:05:03 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/29 17:36:31 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rendering_utils.h"
#include "struct_data.h"

void	ft_render_background(t_data *data, int color)
{
	int	i;
	int	j;

	i = 0;
	(void)color;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			if (i > WINDOW_HEIGHT / 2)
				my_mlx_pixel_put(data, j, i, create_rgb(76, 187, 23));
			else
				my_mlx_pixel_put(data, j, i, create_rgb(135, 206, 235));
			j++;
		}
		i++;
	}
}
