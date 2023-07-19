/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:16:58 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/16 14:12:21 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_color.h"

int	ft_color(t_point p1, t_point p2, t_point p)
{
	int		color;
	float	ratio;

	if (p2.x_p - p1.x_p == 0 && p2.y_p - p1.y_p == 0)
		ratio = 1.0;
	else if (p2.x_p - p1.x_p == 0)
		ratio = (float)(p.y_p - p1.y_p) / (p2.y_p - p1.y_p);
	else
		ratio = (float)(p.x_p - p1.x_p) / (p2.x_p - p1.x_p);
	color = (p2.color - p1.color) * ratio + p1.color;
	return (color);
}

void	ft_set_colors(t_data *data, t_point *p1, t_point *p2)
{
	ft_set_colors_sep(data, p1);
	ft_set_colors_sep(data, p2);
}
