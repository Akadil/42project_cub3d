/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 20:12:08 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/16 16:06:07 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_draw_line.h"

void	ft_draw_line(t_data *data, int i, int j, int direct)
{
	t_point	p1;
	t_point	p2;

	p1.i = i;
	p1.j = j;
	p1.x_p = data->mtrx.node[i][j].x_p;
	p1.y_p = data->mtrx.node[i][j].y_p;
	if (direct == 1)
	{
		p2.i = i;
		p2.j = j + 1;
		p2.x_p = data->mtrx.node[i][j + 1].x_p;
		p2.y_p = data->mtrx.node[i][j + 1].y_p;
	}
	else
	{
		p2.i = i + 1;
		p2.j = j;
		p2.x_p = data->mtrx.node[i + 1][j].x_p;
		p2.y_p = data->mtrx.node[i + 1][j].y_p;
	}
	bresenhams(data, p1, p2);
}

/*
	This algo uses Bresenham's algorithm
*/
void	bresenhams(t_data *data, t_point p1, t_point p2)
{
	t_point	p;
	int		err;
	int		e;

	p.x_p = p1.x_p;
	p.y_p = p1.y_p;
	err = ft_abs(p2.x_p, p1.x_p) - ft_abs(p2.y_p, p1.y_p);
	ft_set_colors(data, &p1, &p2);
	while (p.x_p != p2.x_p || p.y_p != p2.y_p)
	{
		ft_pixel(data, p.x_p, p.y_p, ft_color(p1, p2, p));
		e = 2 * err;
		if (e > -1 * ft_abs(p2.y_p, p1.y_p))
		{
			err -= ft_abs(p2.y_p, p1.y_p);
			p.x_p += ft_slope(p1.x_p, p2.x_p);
		}
		if (e < ft_abs(p2.x_p, p1.x_p))
		{
			err += ft_abs(p2.x_p, p1.x_p);
			p.y_p += ft_slope(p1.y_p, p2.y_p);
		}
	}
	ft_pixel(data, p.x_p, p.y_p, ft_color(p1, p2, p));
}
