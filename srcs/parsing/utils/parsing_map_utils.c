/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:53:22 by aseisenb          #+#    #+#             */
/*   Updated: 2023/08/30 18:19:19 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing_map.h"

int	ft_find_largest_width(t_list *rows)
{
	int	largest;
	int	len;

	largest = -1;
	while (rows)
	{
		len = ft_strlen(rows->content);
		if ((rows->content)[len - 1] == '\n')
			len--;
		if (len > largest)
			largest = len;
		rows = rows->next;
	}
	return (largest);
}

int	valid_char(char c)
{
	if (c == '1' || c == '0' || c == ' ')
		return (0);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (0);
	return (-1);
}

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (0);
	return (-1);
}

/** */
void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}
