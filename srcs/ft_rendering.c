/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:31:58 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/07 11:34:49 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include <stdio.h>
#include "mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_render_background(t_data *data, int color);
void    ft_render_projection(t_data *data);

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

int	create_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return ;
	i = data->img_win.bpp - 8;
	pixel = data->img_win.addr + (y * data->img_win.line_len + x * (data->img_win.bpp / 8));
	while (i >= 0)
	{
		if (data->img_win.endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (data->img_win.bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

