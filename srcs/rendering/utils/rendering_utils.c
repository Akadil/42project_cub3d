/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:05:56 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/29 18:41:39 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering_utils.h"
#include "struct_data.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return ;
	i = data->img_win.bpp - 8;
	pixel = data->img_win.addr + (y * data->img_win.line_len + x
			* (data->img_win.bpp / 8));
	while (i >= 0)
	{
		if (data->img_win.endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (data->img_win.bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}
