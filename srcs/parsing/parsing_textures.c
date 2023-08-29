/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:17:48 by aseisenb          #+#    #+#             */
/*   Updated: 2023/08/29 14:44:00 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parsing_textures.h"

/**
 * @brief Check the textures
 */
int	ft_parsing_textures(t_list *rows, t_data *data)
{
	if (ft_check_texture_names(rows, data) != 0)
		return (ft_putstr_fd("Something wrong with textures2\n", 2), -1);
	if (ft_check_file_existence_wall(data) != 0)
		return (ft_putstr_fd("Something wrong with textures\n", 2), -1);
	return (0);
}

/**
 * @brief Check texture names
 */
int	ft_check_texture_names(t_list *rows, t_data *data)
{
	while (rows)
	{
		if (ft_is_wall(data, rows->content) == 0)
			ft_assign_names_wall(data, rows->content);
		else if (ft_is_ceil_floor(data, rows->content) == 0)
			ft_assign_names_floor_ceil(data, (char *)rows->content);
		else
			return (-1);
		rows = rows->next;
	}
	return (0);
}

/**
 * @brief Check if the textures exists, and save the colors
 */
int	ft_check_file_existence_wall(t_data *data)
{
	int	fd;

	fd = open(data->wall.north.name, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	fd = open(data->wall.south.name, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	fd = open(data->wall.west.name, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	fd = open(data->wall.east.name, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	if (check_valid_rgb(data->wall.floor.name) != 0)
		return (-1);
	data->wall.floor.color = set_rgb_colors(data->wall.floor.name);
	if (check_valid_rgb(data->wall.ceil.name) != 0)
		return (-1);
	data->wall.ceil.color = set_rgb_colors(data->wall.ceil.name);
	return (0);
}
