/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:18:17 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/13 20:52:42 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

int	ft_abs(int a, int b)
{
	if (a - b < 0)
		return (b - a);
	else
		return (a - b);
}

int	ft_slope(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}

void	ft_pixel(t_data *data, int x, int y, int color)
{
	my_mlx_pixel_put(data, x, y, color);
}
