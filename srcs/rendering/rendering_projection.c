/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:52:13 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/30 15:18:55 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rendering_projection.h"

void	ft_render_projection(t_data *data)
{
	t_ray	ray;
	int		x;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		ft_set_ray_vectors(x, &ray, &data->view, data);
		while (data->map[(int)ray.map.y][(int)ray.map.x] != '1')
		{
			if (ray.side_dist.x < ray.side_dist.y)
			{
				ray.side_dist.x += ray.delta_dist.x;
				ray.map.x += ray.step.x;
				ray.side = 0;
			}
			else
			{
				ray.side_dist.y += ray.delta_dist.y;
				ray.map.y += ray.step.y;
				ray.side = 1;
			}
		}
		data->rays[x] = ft_find_dist_perp(&ray);
		ft_draw_column(data, &ray, x++);
	}
}

double	ft_find_dist_perp(t_ray *ray)
{
	double	perp_wall_dist;

	if (ray->side == 0)
		perp_wall_dist = ray->side_dist.x - ray->delta_dist.x;
	else
		perp_wall_dist = ray->side_dist.y - ray->delta_dist.y;
	ray->distance_perp = perp_wall_dist;
	return (perp_wall_dist);
}

void	ft_calculate_side_distances(t_data *data, t_ray *ray);

/*  These assignments have to be separated, because some of them, static    */
/**
 * @brief
 *
 *  2 * x / (double)WINDOW_WIDTH - 1    Ration of the plane
 * ray->dir.x, ray->dir.y               Direction vector of a ray
 * ray->map.x, ray->map.y               The location of ray in cell
 * ray->delta_dis.x, ray->delta_dis.x   The distance of delta for a ray
 */
void	ft_set_ray_vectors(int x, t_ray *ray, t_view *view, t_data *data)
{
	ray->dir.x = view->dir.x + (double)view->plane.x * (2.0 * x / (double)WINDOW_WIDTH - 1);
	ray->dir.y = view->dir.y + (double)view->plane.y * (2.0 * x / (double)WINDOW_WIDTH - 1);
	ray->map.x = (int)data->player.x;
	ray->map.y = (int)data->player.y;
	if (ray->dir.x == 0.0)
		ray->delta_dist.x = DBL_MAX;
	else
		ray->delta_dist.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0.0)
		ray->delta_dist.y = DBL_MAX;
	else
		ray->delta_dist.y = fabs(1 / ray->dir.y);
	ft_calculate_side_distances(data, ray);
}

void	ft_calculate_side_distances(t_data *data, t_ray *ray)
{
	if (ray->dir.x < 0)
	{
		ray->side_dist.x = (data->player.x - ray->map.x) * ray->delta_dist.x;
		ray->step.x = -1;
	}
	else
	{
		ray->side_dist.x = (ray->map.x + 1.0 - data->player.x)
			* ray->delta_dist.x;
		ray->step.x = 1;
	}
	if (ray->dir.y < 0)
	{
		ray->side_dist.y = (data->player.y - ray->map.y) * ray->delta_dist.y;
		ray->step.y = -1;
	}
	else
	{
		ray->side_dist.y = (ray->map.y + 1.0 - data->player.y)
			* ray->delta_dist.y;
		ray->step.y = 1;
	}
}
