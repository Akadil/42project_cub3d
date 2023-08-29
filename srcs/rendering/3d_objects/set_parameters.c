/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_parameters.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:23:02 by aseisenb          #+#    #+#             */
/*   Updated: 2023/08/29 19:23:04 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	ft_set_params(t_data *my_data, int width, int height)
{
	my_data->fdf.param.alpha = 90 - 30 * (1.0 / (fabs(my_data->fdf.pos_p.y)
			+ 1));
	my_data->fdf.param.beta = 180;
	my_data->fdf.param.theta = calculate_angle(my_data->fdf.pos.x,
		my_data->fdf.pos.y);
	if (my_data->fdf.param.theta < 0)
		my_data->fdf.param.theta += 360;
	if (my_data->fdf.param.theta >= 360)
		my_data->fdf.param.theta -= 360;
	my_data->fdf.param.x_offset = width / 2;
	my_data->fdf.param.y_offset = height / 2;
	my_data->fdf.param.grid = ft_find_grid(&my_data->fdf, width) * 3;
	my_data->fdf.param.attitude = ft_find_attitude(&my_data->fdf, height);
}

double	calculate_angle(double x, double y)
{
	double	my_angle;
	double	angleDegrees;

	my_angle = atan2(y, x);
	angleDegrees = my_angle * (180.0 / PI);
	if (angleDegrees < 0)
	{
		angleDegrees += 360.0;
	}
	if (angleDegrees > 359)
	{
		angleDegrees -= 360.0;
	}
	return (angleDegrees);
}

int	ft_find_grid(t_fdf *my_data, int width)
{
	double	returner;
	double	max;
	double	offset;

	offset = my_data->param.x_offset;
	max = my_data->mtrx.height;
	if (max < my_data->mtrx.width)
		max = my_data->mtrx.width;
	returner = (double)width / 2 / max;
	while (returner < 2 && offset > 120)
	{
		offset = offset / 2;
		returner = ((double)width - 2.0 * offset) / max;
	}
	return (returner);
}

int	ft_find_attitude(t_fdf *my_data, int height)
{
	double	returner;
	double	offset;

	offset = my_data->param.y_offset;
	returner = (double)height / 4;
	returner /= my_data->mtrx.z_max - my_data->mtrx.z_min;
	while (returner < 2 && offset > 70)
	{
		offset = offset / 2;
		returner = ((double)height - 2.0 * offset);
		returner /= (my_data->mtrx.z_max - my_data->mtrx.z_min);
	}
	return (returner);
}
