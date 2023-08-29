/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 18:20:04 by aseisenb          #+#    #+#             */
/*   Updated: 2023/08/29 18:44:52 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rendering_utils.h"
#include "struct_data.h"
#include <math.h>
#include <stdio.h>

void	ft_draw_rectangle(t_data *data, int x, int y, int color)
{
	int	i_beg;
	int	i_end;
	int	j_beg;
	int	j_end;

	i_beg = (double)WINDOW_HEIGHT / 4 * 3 + x * 5;
	i_end = (double)WINDOW_HEIGHT / 4 * 3 + (x + 1) * 5;
	while (i_beg < i_end)
	{
		j_beg = (double)WINDOW_WIDTH / 4 * 3 + y * 5;
		j_end = (double)WINDOW_WIDTH / 4 * 3 + (y + 1) * 5;
		while (j_beg < j_end)
		{
			my_mlx_pixel_put(data, j_beg, i_beg, color);
			j_beg++;
		}
		i_beg++;
	}
}

int	ft_abs2(int a, int b)
{
	if (a - b < 0)
		return (b - a);
	else
		return (a - b);
}

int	ft_slope2(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}
