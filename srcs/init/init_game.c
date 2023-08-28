/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:14:37 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/28 20:09:24 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include <stdlib.h>
#include "mlx.h"
#include "libft.h"
#include <math.h>

int ft_get_image_addr(t_data *data);
int    ft_get_images(t_data *data);
void    ft_init_player_view(t_data *data);
void	ft_clean(t_data *data);

int init_game(t_data *data)
{
    t_img   *img;
    int width;
    int height;

    width = WINDOW_WIDTH;
    height = WINDOW_HEIGHT;
    data->mlx_ptr = mlx_init();
    if (!data->mlx_ptr)
        return (-1);
    data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "cub3d");
    if (!data->win_ptr)
        return (ft_clean(data), -1);
    data->img_win.mlx_img = mlx_new_image(data->mlx_ptr, width, height);
    if (!data->img_win.mlx_img)
        return (ft_clean(data), -1);
    img = &data->img_win; 
	data->img_win.addr = mlx_get_data_addr(img->mlx_img, &img->bpp, &img->line_len, &img->endian);
    if (!data->img_win.addr)
        return (ft_clean(data), -1);
    ft_init_player_view(data);
    if (ft_get_images(data) != 0)
        return (ft_putstr_fd("Image failed\n", 2), ft_clean(data), -1);
    if (ft_get_image_addr(data) != 0)
        return (ft_putstr_fd("Image address failed\n", 2), ft_clean(data), -1);
    data->event.rotation_speed = 3;
    data->event.move_fw = false;
    data->event.move_bw = false;
    data->rays = (double *)ft_calloc(sizeof(double), WINDOW_WIDTH);
    return (0);
}

int ft_get_image_addr(t_data *data)
{
    data->wall.north.addr = mlx_get_data_addr(data->wall.north.mlx_img, &data->wall.north.bpp, &data->wall.north.line_len, &data->wall.north.endian);
    if(!data->wall.north.addr)
        return (-1);
    data->wall.south.addr = mlx_get_data_addr(data->wall.south.mlx_img, &data->wall.south.bpp, &data->wall.south.line_len, &data->wall.south.endian);
    if(!data->wall.south.addr)
        return (-1);
    data->wall.west.addr = mlx_get_data_addr(data->wall.west.mlx_img, &data->wall.west.bpp, &data->wall.west.line_len, &data->wall.west.endian);
    if(!data->wall.south.addr)
        return (-1);
    data->wall.east.addr = mlx_get_data_addr(data->wall.east.mlx_img, &data->wall.east.bpp, &data->wall.east.line_len, &data->wall.east.endian);
    if(!data->wall.south.addr)
        return (-1);
    return (0);
}

/*  Norminette  */
int    ft_get_images(t_data *data)
{ 
    data->wall.north.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->wall.north.name, &data->wall.north.width, &data->wall.north.height);
    if(!data->wall.north.mlx_img)
       return (-1);
    data->wall.south.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->wall.south.name, &data->wall.south.width, &data->wall.south.height);
    if(!data->wall.south.mlx_img)
        return (-1);
    data->wall.west.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->wall.west.name, &data->wall.west.width, &data->wall.west.height);
    if(!data->wall.west.mlx_img)
        return (-1);
    data->wall.east.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->wall.east.name, &data->wall.east.width, &data->wall.east.height);
    if(!data->wall.east.mlx_img)
        return (-1);
    return (0);
}

void    ft_init_player_view(t_data *data)
{
    data->view.dir.x = cos(data->angle * PI / 180);
    data->view.dir.y = sin(data->angle * PI / 180);
    data->view.plane.x = 0.66 * sin (data->angle * PI / 180) * -1;
    data->view.plane.y = 0.66 * cos (data->angle * PI / 180);
}

void	ft_clean(t_data *data)
{
    // if(data->wall.north.addr)
    //     free(data->wall.north.addr);
    // if(data->wall.south.addr)
    //     free(data->wall.south.addr);
    // if(data->wall.south.addr)
    //     free(data->wall.south.addr);
    // if(data->wall.south.addr)
    //     free(data->wall.south.addr);
    if(data->wall.north.mlx_img)
    {
        mlx_destroy_image(data->mlx_ptr, data->wall.north.mlx_img);
        // free(data->wall.north.mlx_img);
    }
    if(data->wall.south.mlx_img)
        mlx_destroy_image(data->mlx_ptr, data->wall.south.mlx_img);
        // free(data->wall.south.mlx_img);
    if(data->wall.west.mlx_img)
        mlx_destroy_image(data->mlx_ptr, data->wall.west.mlx_img);
        // free(data->wall.west.mlx_img);
    if(data->wall.east.mlx_img)
        mlx_destroy_image(data->mlx_ptr, data->wall.east.mlx_img);
        // free(data->wall.east.mlx_img);
    if (data->img_win.mlx_img)
        mlx_destroy_image(data->mlx_ptr, data->img_win.mlx_img);
    if (data->win_ptr)
        mlx_destroy_window(data->mlx_ptr, data->win_ptr);
    if (data->mlx_ptr)
	{
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
}
