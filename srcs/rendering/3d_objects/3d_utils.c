/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:22:37 by aseisenb          #+#    #+#             */
/*   Updated: 2023/08/30 15:46:47 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

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

void	ft_set_colors_sep(t_fdf *data, t_point *p1)
{
	data->param.color += 1;
	if (data->mtrx.node[p1->i][p1->j].z == data->mtrx.z_max)
		p1->color = create_rgb2(255, 0, 0);
	else
		p1->color = create_rgb2(255, 255, 255);
}

int	create_rgb2(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

void	ft_set_colors(t_fdf *data, t_point *p1, t_point *p2)
{
	ft_set_colors_sep(data, p1);
	ft_set_colors_sep(data, p2);
}
