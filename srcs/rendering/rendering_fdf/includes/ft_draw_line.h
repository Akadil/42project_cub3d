/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 20:39:26 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/14 21:02:24 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DRAW_LINE_H
# define FT_DRAW_LINE_H

# include "ft_data.h"
# include "ft_point.h"

void	bresenhams(t_data *data, t_point p1, t_point p2);
int		ft_abs(int a, int b);
int		ft_slope(int a, int b);
void	ft_pixel(t_data *data, int x, int y, int color);
void	ft_set_colors(t_data *data, t_point *p1, t_point *p2);
int		ft_color(t_point p1, t_point p2, t_point p);

#endif