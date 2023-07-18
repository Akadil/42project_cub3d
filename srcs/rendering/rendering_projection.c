/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_projection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 11:52:13 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/17 16:11:29 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/rendering_projection.h"

void    ft_render_projection(t_data *data, double ray_distances[WINDOW_WIDTH])
{
    t_ray   ray;
    int x;

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
        ray.distance_perp = ft_find_dist_perp(ray);
        ray_distances[x] = ray.distance_perp;
        ft_draw_column(x, ray, data);
        x++;
    }
}

void    ft_draw_column(int x, t_ray ray, t_data *data)
{
    int lineHeight;
    int draw_start;
    int draw_end;

    float   ratio_x;
    float   ratio_y;
    int     pos_x;
    int     pos_y;
    int     pos_color;

    lineHeight = (int)(WINDOW_HEIGHT / ray.distance_perp);
    draw_start = -lineHeight / 2 + WINDOW_HEIGHT / 2;
    if (draw_start < 0)
        draw_start = 0;
    draw_end = lineHeight / 2 + WINDOW_HEIGHT / 2;
    if (draw_end >= WINDOW_HEIGHT)
        draw_end = WINDOW_HEIGHT - 1;


    if (ray.side == 1)                      // upper or lower 
    {
        ratio_x = data->player.x + ray.distance_perp * ray.dir.x;
        ratio_x -= (int)ratio_x;
        if (ray.dir.y > 0)
            pos_x = (int)((double)data->wall.south.width * ratio_x);
        else
            pos_x = (int)((double)data->wall.north.width * ratio_x);
    }
    if (ray.side == 0)                      // right or left
    {
        ratio_x = data->player.y + ray.distance_perp * ray.dir.y;
        ratio_x -= (int)ratio_x;
        if (ray.dir.x > 0)
            pos_x = (int)((double)data->wall.west.width * ratio_x);
        else
            pos_x = (int)((double)data->wall.east.width * ratio_x);
    }
    while (draw_start < draw_end)
    {
        if (ray.side == 1 && ray.dir.y > 0)
        {
            ratio_y = (float)(2 * draw_start + lineHeight - WINDOW_HEIGHT) / 2 / lineHeight;
            pos_y = (int)(data->wall.north.height * ratio_y);
            pos_color = (float)(pos_y * data->wall.north.line_len) + (pos_x * ((float)data->wall.north.bpp / 8));
            my_mlx_pixel_put(data, x, draw_start, create_rgb((int)data->wall.north.addr[pos_color], (int)data->wall.north.addr[pos_color + 1], (int)data->wall.north.addr[pos_color + 2])); 
        }
        else if (ray.side == 1 && ray.dir.y <= 0)
        {
            ratio_y = (float)(2 * draw_start + lineHeight - WINDOW_HEIGHT) / 2 / lineHeight;
            pos_y = (int)(data->wall.south.height * ratio_y);
            pos_color = (float)(pos_y * data->wall.south.line_len) + (pos_x * ((float)data->wall.south.bpp / 8));
            my_mlx_pixel_put(data, x, draw_start, create_rgb((int)data->wall.south.addr[pos_color], (int)data->wall.south.addr[pos_color + 1], (int)data->wall.south.addr[pos_color + 2])); 
        }
        else if (ray.side == 0 && ray.dir.x > 0)
        {
            ratio_y = (float)(2 * draw_start + lineHeight - WINDOW_HEIGHT) / 2 / lineHeight;
            pos_y = (int)(data->wall.east.height * ratio_y);
            pos_color = (float)(pos_y * data->wall.east.line_len) + (pos_x * ((float)data->wall.east.bpp / 8));
            my_mlx_pixel_put(data, x, draw_start, create_rgb((int)data->wall.east.addr[pos_color], (int)data->wall.east.addr[pos_color + 1], (int)data->wall.east.addr[pos_color + 2]));
        }
        else
        {
            ratio_y = (float)(2 * draw_start + lineHeight - WINDOW_HEIGHT) / 2 / lineHeight;
            pos_y = (int)(data->wall.west.height * ratio_y);
            pos_color = (float)(pos_y * data->wall.west.line_len) + (pos_x * ((float)data->wall.west.bpp / 8));
            my_mlx_pixel_put(data, x, draw_start, create_rgb((int)data->wall.west.addr[pos_color], (int)data->wall.west.addr[pos_color + 1], (int)data->wall.west.addr[pos_color + 2]));
        }
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
