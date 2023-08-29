/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:51:03 by aseisenb          #+#    #+#             */
/*   Updated: 2023/08/29 19:21:28 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../parsing/includes/parsing_map.h"
#include "includes/init.h"

int	ft_init_map(t_list *rows, char **map)
{
	int	i;
	int	j;
	int	largest_width;

	largest_width = ft_find_largest_width(rows);
	i = 0;
	while (rows)
	{
		map[i] = (char *)ft_calloc(sizeof(char), largest_width + 1);
		if (!map[i])
			return (-1);
		j = 0;
		while (((char *)rows->content)[j] && ((char *)rows->content)[j] != '\n')
		{
			map[i][j] = ((char *)rows->content)[j];
			j++;
		}
		ft_memset(map[i] + j, ' ', largest_width - j);
		map[i][j] = '\0';
		rows = rows->next;
		i++;
	}
	map[i] = NULL;
	return (0);
}

void	ft_init_player(t_data *data, char p, int i, int j)
{
	data->player.x = j + 0.5;
	data->player.y = i + 0.5;
	data->sprite_pos.x = j + 0.5;
	data->sprite_pos.y = i + 0.5;
	if (p == 'N')
		data->angle = 270.0;
	else if (p == 'E')
		data->angle = 0.0;
	else if (p == 'S')
		data->angle = 90.0;
	else
		data->angle = 180.0;
}

void	ft_init_player_view(t_data *data)
{
	data->view.dir.x = cos(data->angle * PI / 180);
	data->view.dir.y = sin(data->angle * PI / 180);
	data->view.plane.x = 0.66 * sin(data->angle * PI / 180) * -1;
	data->view.plane.y = 0.66 * cos(data->angle * PI / 180);
}
