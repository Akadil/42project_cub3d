/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:52:13 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/08 15:10:10 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"

#define PI 3.14

#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <float.h>
#include <unistd.h>

typedef struct s_ray
{
    t_vector    dir;    // Or change it to pos
    t_vector    map;
    t_vector    delta_dist;
    t_vector    side_dist;
    t_vector    step;
    int         side;
    double      distance_perp;
}   t_ray;

typedef struct  s_color
{
    int r;
    int g;
    int b;
}       t_color;

double  ft_find_dist_perp(t_ray ray);
void    ft_set_ray_vectors(int x, t_ray *ray, t_view *view, t_data *data);
void    ft_set_direction_vector(float angle, t_view  *view);
void    ft_draw_column(int x, t_ray ray, t_data *data);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
int     create_rgb(int r, int g, int b);

void    ft_render_projection(t_data *data)
{
    t_ray   ray;
    int x;

    x = 0;
    ft_set_direction_vector(data->angle, &data->view);     // Move it to previous steps
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
        ray.distance_perp = ft_find_dist_perp(ray);
        ft_draw_column(x, ray, data);
        // printf("%lf\n", ray.distance_perp);
        // usleep(2000);
        x++;
    }
    // printf("=======================================================================\n");
    // printf("=======================================================================\n");
}

void    ft_draw_column(int x, t_ray ray, t_data *data)
{
    int lineHeight;
    int draw_start;
    int draw_end;

    lineHeight = (int)(WINDOW_HEIGHT / ray.distance_perp);
    draw_start = -lineHeight / 2 + WINDOW_HEIGHT / 2;
    if (draw_start < 0)
        draw_start = 0;
    draw_end = lineHeight / 2 + WINDOW_HEIGHT / 2;
    if (draw_end >= WINDOW_HEIGHT)
        draw_end = WINDOW_HEIGHT - 1;
    while (draw_start < draw_end)
    {
        my_mlx_pixel_put(data, x, draw_start, create_rgb(255, 0, 0));
        draw_start++;
    }
}

double  ft_find_dist_perp(t_ray ray)
{
    /*  I think here shouldn't be any substraction. Because I changed the dda algorithm */
    if (ray.side == 0)
        return (ray.side_dist.x - ray.delta_dist.x);
    else
        return (ray.side_dist.y - ray.delta_dist.y);
}

/*  These assignments have to be separated, because some of them, static    */
void    ft_set_ray_vectors(int x, t_ray *ray, t_view *view, t_data *data)
{
    double ratio_plane;

    /* The ratio in the plane*/
    ratio_plane = 2 * x / (double)WINDOW_WIDTH - 1;
    
    /*  The direction vector of ray */
    ray->dir.x = view->dir.x + view->plane.x * ratio_plane;
    ray->dir.y = view->dir.y + view->plane.y * ratio_plane;

    /*  The location of ray in the cell  */
    ray->map.x = (int)data->player.x;
    ray->map.y = (int)data->player.y;

    /*  The distance of delta for a ray  */
    if (ray->dir.x == 0.0)
        ray->delta_dist.x = DBL_MAX;
    else
        ray->delta_dist.x = fabs(1 / ray->dir.x);
    if (ray->dir.y == 0.0)
        ray->delta_dist.y = DBL_MAX;
    else
        ray->delta_dist.y = fabs(1 / ray->dir.y);
    
    /*  The side steps  */
    if (ray->dir.x < 0)
    {
        ray->side_dist.x = (data->player.x - ray->map.x) * ray->delta_dist.x;
        ray->step.x = -1;
    }
    else
    {
        ray->side_dist.x = (ray->map.x + 1.0 - data->player.x) * ray->delta_dist.x;
        ray->step.x = 1;
    }
    
    if (ray->dir.y < 0)
    {
        ray->side_dist.y = (data->player.y - ray->map.y) * ray->delta_dist.y;
        ray->step.y = -1;
    }
    else
    {
        ray->side_dist.y = (ray->map.y + 1.0 - data->player.y) * ray->delta_dist.y;
        ray->step.y = 1;
    }
}



/*  =========================================================     */
    /*  Maybe this function have to be done in ft_handling  */
            /*  and variables set in the t_data */
/*  =========================================================     */
void    ft_set_direction_vector(float angle, t_view  *view)
{
    view->dir.x = cos(angle * PI / 180);
    view->dir.y = sin(angle * PI / 180);
    view->plane.x = 0.66 * sin (angle * PI / 180) * -1;
    view->plane.y = 0.66 * cos (angle * PI / 180);
}
