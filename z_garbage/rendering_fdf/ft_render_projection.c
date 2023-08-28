/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 15:09:52 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/16 16:06:41 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_render_projection.h"

void	ft_render_projection(t_data *data)
{
	int	i;
	int	j;

	ft_set_x_y(data);
	i = 0;
	while (i < data->mtrx.height)
	{
		j = 0;
		while (j < data->mtrx.width)
		{
			if (j + 1 != data->mtrx.width)
				ft_draw_line(data, i, j, 1);
			if (i + 1 != data->mtrx.height)
				ft_draw_line(data, i, j, 0);
			j++;
		}
		i++;
	}
}

void	ft_set_x_y(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->mtrx.height)
	{
		j = 0;
		while (j < data->mtrx.width)
		{
			ft_transform(data, i, j);
			j++;
		}
		i++;
	}
}
