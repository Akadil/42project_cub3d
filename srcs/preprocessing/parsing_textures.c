/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:17:48 by aseisenb          #+#    #+#             */
/*   Updated: 2023/07/14 18:36:59 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/parsing_textures.h"

int	ft_parsing_textures(t_list *rows, t_data *data)
{
	if (ft_check_direction_names(rows, data) != 0)
		return (-1);
	if (ft_check_file_existence_wall(data) != 0)
		return (-1);
	return (0);
}

void	ft_check_direction_names(t_list *head, t_data *data)
{
	while (ft_strncmp((char *)head->content, "1", 1) != 0)
	{
		if (ft_is_wall(data, (char *)head->content) == 1)
			ft_assign_names_wall(data, head);
		else if (ft_is_ceil_floor(data, (char *)head->content) == 1)
			ft_assign_names_floor_ceil(data, (char *)head->content);
		else
			return (ft_printf("q"), -1); // Fix me
		head = head->next;
	}
	return (0);
}

int	ft_check_file_existence_wall(t_data *data)
{
	int	fd;

	fd = open(data->wall.north.name + 3, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	fd = open(data->wall.south.name + 3, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	fd = open(data->wall.west.name + 3, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	fd = open(data->wall.east.name + 3, O_RDONLY);
	if (fd == -1)
		return (-1);
	close(fd);
	if (check_valid_rgb(data->wall.floor.name + 2) == 1)
		return (-1);
	data->wall.floor.color = set_rgb_colors(data->wall.floor.name + 2);
	if (check_valid_rgb(data->wall.ceil.name + 2) == 1)
		return (-1);
	data->wall.ceil.color = set_rgb_colors(data->wall.ceil.name + 2);
	return (0);
}
