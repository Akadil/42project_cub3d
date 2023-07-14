/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:26:03 by aseisenb          #+#    #+#             */
/*   Updated: 2023/07/14 18:32:54 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct_data.h"
#include "struct_list.h"

int	ft_is_wall(t_data *data, char *content)
{
	if (ft_strncmp(content, "NO ", 3) == 0 && !data->wall.north.name)
		return (1);
	else if (ft_strncmp(content, "SO ", 3) == 0 && !data->wall.souht.name)
		return (1);
	else if (ft_strncmp(content, "WE ", 3) == 0 && !data->wall.west.name)
		return (1);
	else if (ft_strncmp(content, "EA ", 3) == 0 && !data->wall.east.name)
		return (1);
	return (0);
}

int	ft_is_ceil_floor(t_data *data, char *content)
{
	if (!ft_strncmp((char *)head->content, "C ", 2))
		if (!data->wall.ceil.name)
			return (1);
		else if (!ft_strncmp((char *)head->content, "F ", 2))
			if (!data->wall.floor.name)
				return (1);
	return (0);
}

void	ft_assign_names_wall(t_data *data, t_list *row)
{
	if (ft_strncmp((char *)row->content, "NO ", 3) == 0)
	{
		data->wall.north.name = (char *)row->content + 3;
		data->wall.north.name[ft_strlen(data->wall.north.name) - 1] = '\0';
	}
	else if (ft_strncmp((char *)row->content, "SO ", 3) == 0)
	{
		data->wall.south.name = (char *)row->content + 3;
		data->wall.south.name[ft_strlen(data->wall.south.name) - 1] = '\0';
	}
	else if (ft_strncmp((char *)row->content, "WE ", 3) == 0)
	{
		data->wall.west.name = (char *)row->content + 3;
		data->wall.west.name[ft_strlen(data->wall.west.name) - 1] = '\0';
	}
	else if (ft_strncmp((char *)row->content, "EA ", 3) == 0)
	{
		data->wall.east.name = (char *)row->content + 3;
		data->wall.east.name[ft_strlen(data->wall.east.name) - 1] = '\0';
	}
}

void	ft_assign_names_floor_ceil(t_data *data, t_list *row)
{
	if (ft_strncmp((char *)row->content, "C ", 2) == 0)
	{
		data->wall.ceil.name = (char *)row->content + 2;
		data->wall.ceil.name[ft_strlen(data->wall.ceil.name) - 1] == '\0';
	}
	else if (ft_strncmp((char *)row->content, "F ", 2) == 0)
	{
		data->wall.floor.name = (char *)row->content + 2;
		data->wall.floor.name[ft_strlen(data->wall.floor.name) - 1] == '\0';
	}
}
