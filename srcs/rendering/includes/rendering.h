/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:09:38 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/29 19:16:26 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "mlx.h"
# include "rendering_utils.h"
# include "struct_data.h"
# include "struct_ray.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

void	ft_react_to_event(t_data *data);
void	ft_render_background(t_data *data, int color);
void	ft_render_projection(t_data *data);
void	ft_rendering_sprites(t_data *data);
void	ft_rendering_minimap(t_data *data);
void	ft_rendering_minimap_circle(t_data *data);
void	ft_rendering_3d_object(t_data *data);
void	ft_transform(t_fdf *data, int i, int j);
void	ft_set_params(t_data *my_data, int width, int height);
void	ft_render_3d(t_data *data, int x_offset);
void	ft_set_x_y(t_data *data);
void	ft_transform(t_fdf *data, int i, int j);
float	ft_rad(int angle);
void	ft_draw_line(t_data *data, int i, int j, int direct, int x_offset);
void	bresenhams(t_data *data, t_point p1, t_point p2, int x_offset);
void	ft_set_colors(t_fdf *data, t_point *p1, t_point *p2);
void	ft_set_colors_sep(t_fdf *data, t_point *p1);
int		create_rgb2(int r, int g, int b);
int		ft_abs(int a, int b);
int		ft_slope(int a, int b);
void	ft_pixel(t_data *data, int x, int y, int color, int x_offset);
int		ft_color(t_point p1, t_point p2, t_point p);
double	calculate_angle(double x, double y);
int		ft_find_grid(t_fdf *my_data, int width);
int		ft_find_attitude(t_fdf *my_data, int height);

#endif
