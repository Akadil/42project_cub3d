/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3d_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:22:37 by aseisenb          #+#    #+#             */
/*   Updated: 2023/08/30 16:07:25 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	ft_set_x_y(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->fdf.mtrx.height)
	{
		j = 0;
		while (j < data->fdf.mtrx.width)
		{
			ft_transform(&data->fdf, i, j);
			j++;
		}
		i++;
	}
}

void	ft_transform(t_fdf *data, int i, int j)
{
	double	x_p;
	double	y_p;
	double	x;
	double	y;
	double	z;

	x = (double)data->mtrx.node[i][j].x * data->param.grid;
	y = (double)data->mtrx.node[i][j].y * data->param.grid;
	z = (double)data->mtrx.node[i][j].z * data->param.attitude;
	x_p = 0.0;
	x_p += x * cos(ft_rad(data->param.theta)) * cos(ft_rad(data->param.beta));
	x_p -= z * sin(ft_rad(data->param.beta));
	x_p -= y * sin(ft_rad(data->param.theta)) * cos(ft_rad(data->param.beta));
	x_p += data->param.x_offset;
	y_p = 0.0;
	y_p += x * sin(ft_rad(data->param.theta)) * cos(ft_rad(data->param.alpha));
	y_p += y * cos(ft_rad(data->param.theta)) * cos(ft_rad(data->param.alpha));
	y_p += x * cos(ft_rad(data->param.theta)) * sin(ft_rad(data->param.beta))
		* sin(ft_rad(data->param.alpha));
	y_p -= y * sin(ft_rad(data->param.theta)) * sin(ft_rad(data->param.beta))
		* sin(ft_rad(data->param.alpha));
	y_p += z * cos(ft_rad(data->param.beta)) * sin(ft_rad(data->param.alpha));
	y_p += data->param.y_offset;
	data->mtrx.node[i][j].x_p = (int)x_p;
	data->mtrx.node[i][j].y_p = (int)y_p;
}

float	ft_rad(int angle)
{
	return (angle * (3.142857 / 180.0));
}
