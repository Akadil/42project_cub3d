/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 19:22:45 by aseisenb          #+#    #+#             */
/*   Updated: 2023/08/30 13:48:34 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"

void	ft_draw_line(t_data *data, int i, int j, int direct, int x_offset)
{
	t_point	p1;
	t_point	p2;

	p1.i = i;
	p1.j = j;
	p1.x_p = data->fdf.mtrx.node[i][j].x_p;
	p1.y_p = data->fdf.mtrx.node[i][j].y_p;
	if (direct == 1)
	{
		p2.i = i;
		p2.j = j + 1;
		p2.x_p = data->fdf.mtrx.node[i][j + 1].x_p;
		p2.y_p = data->fdf.mtrx.node[i][j + 1].y_p;
	}
	else
	{
		p2.i = i + 1;
		p2.j = j;
		p2.x_p = data->fdf.mtrx.node[i + 1][j].x_p;
		p2.y_p = data->fdf.mtrx.node[i + 1][j].y_p;
	}
	bresenhams(data, p1, p2, x_offset);
	if (direct == 1)
	{
		p2.i = i;
		p2.j = j + 1;
		p2.x_p = data->fdf.mtrx.node[i][j + 1].x_p + 1;
		p2.y_p = data->fdf.mtrx.node[i][j + 1].y_p + 1;
	}
	else
	{
		p2.i = i + 1;
		p2.j = j;
		p2.x_p = data->fdf.mtrx.node[i + 1][j].x_p + 1;
		p2.y_p = data->fdf.mtrx.node[i + 1][j].y_p + 1;
	}
	bresenhams(data, p1, p2, x_offset);
	// if (direct == 1)
	// {
	// 	p2.i = i;
	// 	p2.j = j + 1;
	// 	p2.x_p = data->fdf.mtrx.node[i][j + 1].x_p - 1;
	// 	p2.y_p = data->fdf.mtrx.node[i][j + 1].y_p - 1;
	// }
	// else
	// {
	// 	p2.i = i + 1;
	// 	p2.j = j;
	// 	p2.x_p = data->fdf.mtrx.node[i + 1][j].x_p - 1;
	// 	p2.y_p = data->fdf.mtrx.node[i + 1][j].y_p - 1;
	// }
	// bresenhams(data, p1, p2, x_offset);
}

void	bresenhams(t_data *data, t_point p1, t_point p2, int x_offset)
{
	t_point	p;
	int		err;
	int		e;

	p.x_p = p1.x_p;
	p.y_p = p1.y_p;
	err = ft_abs(p2.x_p, p1.x_p) - ft_abs(p2.y_p, p1.y_p);
	ft_set_colors(&data->fdf, &p1, &p2);
	while (p.x_p != p2.x_p || p.y_p != p2.y_p)
	{
		ft_pixel(data, p.x_p + 0, p.y_p + 0, ft_color(p1, p2, p), x_offset);
		ft_pixel(data, p.x_p + 0, p.y_p + 1, ft_color(p1, p2, p), x_offset);
		ft_pixel(data, p.x_p + 1, p.y_p + 0, ft_color(p1, p2, p), x_offset);
		ft_pixel(data, p.x_p + 1, p.y_p + 1, ft_color(p1, p2, p), x_offset);
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
	ft_pixel(data, p.x_p, p.y_p, ft_color(p1, p2, p), x_offset);
}

void	ft_set_colors(t_fdf *data, t_point *p1, t_point *p2)
{
	ft_set_colors_sep(data, p1);
	ft_set_colors_sep(data, p2);
}

void	ft_pixel(t_data *data, int x, int y, int color, int x_offset)
{
	char	*pixel;
	int		i;

	x = x + x_offset;
	y = y + WINDOW_HEIGHT / 2;
	if (x < 0 || x > WINDOW_WIDTH || y < 0 || y > WINDOW_HEIGHT)
		return ;
	if (data->fdf.length > data->rays[x - 1])
		return ;
	i = data->img_win.bpp - 8;
	pixel = data->img_win.addr + (y * data->img_win.line_len + x
		* (data->img_win.bpp / 8));
	while (i >= 0)
	{
		if (data->img_win.endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (data->img_win.bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

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
