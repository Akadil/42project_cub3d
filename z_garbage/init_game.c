/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:14:37 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/30 17:24:26 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/init.h"

int	init_game(t_data *data)
{
	t_img	*img;
	int		width;
	int		height;

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
	data->img_win.addr = mlx_get_data_addr(img->mlx_img, &img->bpp,
			&img->line_len, &img->endian);
	if (!data->img_win.addr)
		return (ft_clean(data), -1);
	init_game2(data);
	return (0);
}

int	init_game2(t_data *data)
{
	ft_init_player_view(data);
	if (ft_get_images(data) != 0)
		return (ft_putstr_fd("Image failed\n", 2), ft_clean(data), -1);
	if (ft_get_image_addr(data) != 0)
		return (ft_putstr_fd("Image address failed\n", 2), ft_clean(data), -1);
	data->event.rotation_speed = 3;
	data->event.move_fw = false;
	data->event.move_bw = false;
	data->rays = (double *)ft_calloc(sizeof(double), WINDOW_WIDTH);
	if (!data->rays)
		return (ft_putstr_fd("Rays failed\n", 2), ft_clean(data), -1);
	return (0);
}

void	ft_clean(t_data *data)
{
	if (data->wall.north.mlx_img)
	{
		mlx_destroy_image(data->mlx_ptr, data->wall.north.mlx_img);
		// free(data->wall.north.mlx_img);
	}
	if (data->wall.south.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->wall.south.mlx_img);
	// free(data->wall.south.mlx_img);
	if (data->wall.west.mlx_img)
		mlx_destroy_image(data->mlx_ptr, data->wall.west.mlx_img);
	// free(data->wall.west.mlx_img);
	if (data->wall.east.mlx_img)
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
