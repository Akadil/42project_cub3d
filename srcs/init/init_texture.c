/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:51:20 by aseisenb          #+#    #+#             */
/*   Updated: 2023/08/29 17:51:22 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/init.h"

int	ft_get_image_addr(t_data *data)
{
	data->wall.north.addr = mlx_get_data_addr(data->wall.north.mlx_img,
			&data->wall.north.bpp, &data->wall.north.line_len,
			&data->wall.north.endian);
	if (!data->wall.north.addr)
		return (-1);
	data->wall.south.addr = mlx_get_data_addr(data->wall.south.mlx_img,
			&data->wall.south.bpp, &data->wall.south.line_len,
			&data->wall.south.endian);
	if (!data->wall.south.addr)
		return (-1);
	data->wall.west.addr = mlx_get_data_addr(data->wall.west.mlx_img,
			&data->wall.west.bpp, &data->wall.west.line_len,
			&data->wall.west.endian);
	if (!data->wall.south.addr)
		return (-1);
	data->wall.east.addr = mlx_get_data_addr(data->wall.east.mlx_img,
			&data->wall.east.bpp, &data->wall.east.line_len,
			&data->wall.east.endian);
	if (!data->wall.south.addr)
		return (-1);
	return (0);
}

/*  Norminette  */
int	ft_get_images(t_data *data)
{
	data->wall.north.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->wall.north.name, &data->wall.north.width,
			&data->wall.north.height);
	if (!data->wall.north.mlx_img)
		return (-1);
	data->wall.south.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->wall.south.name, &data->wall.south.width,
			&data->wall.south.height);
	if (!data->wall.south.mlx_img)
		return (-1);
	data->wall.west.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->wall.west.name, &data->wall.west.width,
			&data->wall.west.height);
	if (!data->wall.west.mlx_img)
		return (-1);
	data->wall.east.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr,
			data->wall.east.name, &data->wall.east.width,
			&data->wall.east.height);
	if (!data->wall.east.mlx_img)
		return (-1);
	return (0);
}
