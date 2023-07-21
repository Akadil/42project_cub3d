/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_minimap.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 17:10:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/21 12:28:17 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "includes/rendering_utils.h"
#include <math.h>

void    ft_draw_rectangle(t_data *data, int x, int y, int color)
{
    int i_beg;
    int i_end;
    int j_beg;
    int j_end;

    i_beg = (double)WINDOW_HEIGHT / 4 * 3 + x * 5;
    i_end = (double)WINDOW_HEIGHT / 4 * 3 + (x + 1) * 5;
    while (i_beg < i_end)
    {
        j_beg = (double)WINDOW_WIDTH / 4 * 3 + y * 5;
        j_end = (double)WINDOW_WIDTH / 4 * 3 + (y + 1) * 5;
        while (j_beg < j_end)
        {
            my_mlx_pixel_put(data, j_beg, i_beg, color);
            j_beg++;
        }
        i_beg++;
    }
}

int	ft_abs2(int a, int b)
{
	if (a - b < 0)
		return (b - a);
	else
		return (a - b);
}

int	ft_slope2(int a, int b)
{
	if (a < b)
		return (1);
	else
		return (-1);
}

void	bresenhams2(t_data *data, t_vector *p1, t_vector *p2)
{
	t_vector	p;
	int		err;
	int		e;

	p.x = (int)p1->x;
	p.y = (int)p1->y;
	err = ft_abs2((int)p2->x, (int)p1->x) - ft_abs2((int)p2->y, (int)p1->y);
	while ((int)p.x != (int)p2->x || (int)p.y != (int)p2->y)
	{
        my_mlx_pixel_put(data, (int)p.x, (int)p.y, create_rgb(255, 255, 255));
		e = 2 * err;
		if (e > -1 * ft_abs2((int)p2->y, (int)p1->y))
		{
			err -= ft_abs2((int)p2->y, (int)p1->y);
			p.x += ft_slope2((int)p1->x, (int)p2->x);
		}
		if (e < ft_abs2((int)p2->x, (int)p1->x))
		{
			err += ft_abs2((int)p2->x, (int)p1->x);
			p.y += ft_slope2((int)p1->y, (int)p2->y);
		}
	}
    my_mlx_pixel_put(data, (int)p.x, (int)p.y, create_rgb(255, 255, 255));
}

#include <stdio.h>

void    ft_draw_player(t_data *data)
{
    t_vector    map_ray;
    t_vector    player;
    int i_beg;
    int i_end;
    int j_beg;
    int j_end;

    i_beg = (double)WINDOW_HEIGHT / 4.0 * 3.0 + data->player.y * 5.0 - 1;
    i_end = (double)WINDOW_HEIGHT / 4.0 * 3 + data->player.y * 5.0 + 1;
    while (i_beg < i_end)
    {
        j_beg = (double)WINDOW_WIDTH / 4.0 * 3.0 + data->player.x * 5.0 - 1;
        j_end = (double)WINDOW_WIDTH / 4.0 * 3.0 + data->player.x * 5.0 + 1;
        while (j_beg < j_end)
        {
            my_mlx_pixel_put(data, j_beg, i_beg, create_rgb(0, 255, 0));
            j_beg++;
        }
        i_beg++;
    }
    player.y = (double)WINDOW_HEIGHT / 4.0 * 3.0 + data->player.y * 5.0;
    player.x = (double)WINDOW_WIDTH / 4.0 * 3.0 + data->player.x * 5.0;
    map_ray.x = player.x + data->view.dir.x * 5 * data->rays[WINDOW_WIDTH / 2];
    map_ray.y = player.y + data->view.dir.y * 5 * data->rays[WINDOW_WIDTH / 2];
    bresenhams2(data, &player, &map_ray);
    map_ray.x = player.x + (data->view.dir.x * 5 + data->view.plane.x * 3) * data->rays[WINDOW_WIDTH - 1];
    map_ray.y = player.y + (data->view.dir.y * 5 + data->view.plane.y * 3) * data->rays[WINDOW_WIDTH - 1];
    bresenhams2(data, &player, &map_ray);
    map_ray.x = player.x + (data->view.dir.x * 5 - data->view.plane.x * 3) * data->rays[0];
    map_ray.y = player.y + (data->view.dir.y * 5 - data->view.plane.y * 3) * data->rays[0];
    bresenhams2(data, &player, &map_ray);
    map_ray.x = player.x + (data->view.dir.x * 5 + data->view.plane.x * 1.5) * data->rays[WINDOW_WIDTH / 4 * 3];
    map_ray.y = player.y + (data->view.dir.y * 5 + data->view.plane.y * 1.5) * data->rays[WINDOW_WIDTH / 4 * 3];
    bresenhams2(data, &player, &map_ray);
    map_ray.x = player.x + (data->view.dir.x * 5 - data->view.plane.x * 1.5) * data->rays[WINDOW_WIDTH / 4];
    map_ray.y = player.y + (data->view.dir.y * 5 - data->view.plane.y * 1.5) * data->rays[WINDOW_WIDTH / 4];
    bresenhams2(data, &player, &map_ray);
}

void    ft_rendering_minimap(t_data *data)
{
    int x;
    int y;

    x = 0;
    while (data->map[x])
    {
        y = 0;
        while (data->map[x][y])
        {
            // if (data->map[x][y] == '1')
            //     ft_draw_rectangle(data, x, y, create_rgb(255, 0, 0));
            if (data->map[x][y] == '0' || data->map[x][y] == 'N')
                ft_draw_rectangle(data, x, y, create_rgb(0, 0, 255));
            y++;
        }       
        x++;
    }
    ft_draw_player(data);
}

void    ft_rendering_minimap_circle(t_data *data)
{
    int	i;
	int	j;

	i = (int)(WINDOW_HEIGHT / 4 * 3);
	while (i < WINDOW_HEIGHT)
	{
		j = (int)(WINDOW_WIDTH / 4 * 3);
		while (j < WINDOW_WIDTH)
		{
            if (pow(j - (int)(WINDOW_WIDTH / 4 * 3.5), 2) + pow(i - (int)(WINDOW_HEIGHT / 4 * 3.5), 2) < pow((double)(WINDOW_HEIGHT / 8) + 1, 2))
            {
                if (pow(j - (int)(WINDOW_WIDTH / 4 * 3.5), 2) + pow(i - (int)(WINDOW_HEIGHT / 4 * 3.5), 2) < pow((double)(WINDOW_HEIGHT / 8), 2))
                    my_mlx_pixel_put(data, j, i, create_rgb(0, 0, 0));
                else
                    my_mlx_pixel_put(data, j, i, create_rgb(255, 255, 255));
            }
            j++;
		}
		i++;
	}
}
