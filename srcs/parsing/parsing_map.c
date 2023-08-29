/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:17:37 by aseisenb          #+#    #+#             */
/*   Updated: 2023/08/29 17:08:23 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../init/includes/init.h"
#include "includes/parsing_map.h"

/**
 * @brief       Parse and check the map
 */
int	ft_parsing_map(t_list *rows, t_data *data)
{
	char	**map;

	map = (char **)ft_calloc(sizeof(char *), ft_lstsize(rows) + 1);
	if (!map)
		return (ft_putstr_fd("Malloc failed\n", 2), -1);
	if (ft_init_map(rows, map) != 0)
		return (ft_putstr_fd("Malloc failed\n", 2), ft_free_map(map), -1);
	if (ft_check_proper_walls(map) != 0)
		return (ft_putstr_fd("Invalid map\n", 2), ft_free_map(map), -1);
	if (ft_check_player_existense(map, data) != 0)
		return (ft_free_map(map), -1);
	data->map = map;
	return (0);
}

/**
 * @brief Check if the map is surrounded with walls
 */
int	ft_check_proper_walls(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (valid_char(map[i][j]) != 0)
				return (-1);
			if (map[i][j] == '0' || is_player(map[i][j]) == 0)
			{
				if (i == 0 || j == 0 || !map[i + 1] || !map[i][j + 1])
					return (-1);
				else if (map[i][j + 1] == ' ' || map[i][j - 1] == ' ')
					return (-1);
				else if (map[i + 1][j] == ' ' || map[i - 1][j] == ' ')
					return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_player_existense(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player(map[i][j]) == 0)
			{
				if (data->player.x != 0.0)
					return (ft_putstr_fd("Player should be unique.\n", 2), -1);
				ft_init_player(data, map[i][j], i, j);
			}
			j++;
		}
		i++;
	}
	if (data->player.x == 0.0)
		return (ft_putstr_fd("Player doesn't exist.\n", 2), -1);
	return (0);
}
