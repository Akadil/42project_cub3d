/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_ray.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 13:01:29 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/29 19:24:40 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_RAY_H
# define STRUCT_RAY_H

typedef struct s_ray
{
	t_vector	dir;
	t_vector	map;
	t_vector	delta_dist;
	t_vector	side_dist;
	t_vector	step;
	int			side;
	double		distance_perp;
}				t_ray;

#endif