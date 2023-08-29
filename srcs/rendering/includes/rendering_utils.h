/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:10:14 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/29 18:33:50 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_UTILS_H
# define RENDERING_UTILS_H

# include "struct_data.h"
# include "struct_ray.h"
# include <math.h>
# include <stdio.h>

int		create_rgb(int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_get_the_colors_west(t_data *data, t_draw *draw);
void	ft_get_the_colors_east(t_data *data, t_draw *draw);
void	ft_get_the_colors_north(t_data *data, t_draw *draw);
void	ft_get_the_colors_south(t_data *data, t_draw *draw);
double	ft_calculate_the_ratio(t_draw *draw, int i);
void	ft_draw_column_east(t_data *data, t_ray *ray, t_draw *draw);
void	ft_draw_column_west(t_data *data, t_ray *ray, t_draw *draw);
void	ft_draw_column_south(t_data *data, t_ray *ray, t_draw *draw);
void	ft_draw_column_north(t_data *data, t_ray *ray, t_draw *draw);
int		create_rgb(int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	ft_move_forward(t_data *data);
void	ft_move_backward(t_data *data);
void	ft_move_right(t_data *data);
void	ft_move_left(t_data *data);
void	ft_rotate_right(t_data *data);
void	ft_rotate_left(t_data *data);
void	ft_set_direction_vector(float angle, t_view *view);
void	ft_draw_rectangle(t_data *data, int x, int y, int color);
int		ft_abs2(int a, int b);
int		ft_slope2(int a, int b);

#endif
