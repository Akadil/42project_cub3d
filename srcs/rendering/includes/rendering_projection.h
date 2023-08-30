/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_projection.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 14:50:30 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/30 15:17:41 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_PROJECTION_H
# define RENDERING_PROJECTION_H

# include "struct_data.h"
# include "struct_ray.h"
# include <float.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

double	ft_find_dist_perp(t_ray *ray);
void	ft_set_ray_vectors(int x, t_ray *ray, t_view *view, t_data *data);
void	ft_set_direction_vector(float angle, t_view *view);
void	ft_draw_column(t_data *data, t_ray *ray, int x);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int		create_rgb(int r, int g, int b);

#endif
