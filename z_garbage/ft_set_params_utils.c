/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_params_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/16 11:55:29 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/16 20:55:23 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"

int	ft_find_grid(t_data *my_data)
{
	float	returner;
	float	max;
	int		offset;

	offset = my_data->param.x_offset;
	max = my_data->mtrx.height;
	if (max < my_data->mtrx.width)
		max = my_data->mtrx.width;
	returner = WINDOW_WIDTH / 2 / max;
	while (returner < 2 && offset > 120)
	{
		offset = offset / 2;
		returner = (WINDOW_WIDTH - offset * 2) / max;
	}
	return (returner);
}

int	ft_find_attitude(t_data *my_data)
{
	float	returner;
	int		offset;

	offset = my_data->param.y_offset;
	returner = (float)(WINDOW_HEIGHT - 0) / 4;
	returner /= my_data->mtrx.z_max - my_data->mtrx.z_min;
	while (returner < 2 && offset > 70)
	{
		offset = offset / 2;
		returner = (WINDOW_HEIGHT - offset * 2);
		returner /= (my_data->mtrx.z_max - my_data->mtrx.z_min);
	}
	return (returner);
}
