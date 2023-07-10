/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:34:55 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/03 12:47:04 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "libft.h"
#include <stdlib.h>

/**
 * @brief       Parse and check the map
 *  
 * @return (int)    the result. 0 if everything is ok, - if wrong 
 */
int ft_parsing_map(t_list *rows, t_data *data)
{
    char    **map;
    int     i;

    if (ft_lstsize(rows) <= 2)
        return (-1);
    if (ft_check_player_existense(rows, data) != 0)
        return (-1);
    map = (char **)malloc(sizeof(char *) * (ft_lstsize(rows) + 1));
    if (!map)
        return (ft_lstclear(&rows, &free), -1);
    ft_init_map(rows, map);
    ft_lstclear(&rows, NULL);
	if (ft_check_proper_walls(rows) != 0)
        return (-1);
}

int ft_check_player_existense(t_list *rows, t_data *data)
{
    char    *row;
    int     i;
    int     row_num;

    row_num = 0;
    while (rows)
    {
        row = (char *)rows->content;
        i = 0;
        while (row[i])
        {
            if(row[i] == 'N' || row[i] == 'E' ||row[i] == 'S' || row[i] == 'W' )
            {
                if(data->player.x != 0.0)
                    return (ft_printf("Player should be unique.\n"), 0);
                ft_init_player(data, row[i], row_num, i);
            }
            i++;
        }
        row_num++;
        rows = rows->next;
    }
}

void    ft_init_player(t_data *data, char p, int row_num, int i)
{
    data->player.x = row_num;
    data->player.y = i;
    if (p == 'N')
        data->angle = 270.0;
    else if (p == 'E')
        data->angle = 0.0;
    else if (p == 'S')
        data->angle = 90.0;
    else
        data->angle = 180.0;
}

void	ft_init_map(t_list *rows, char **map)
{
	int	i;

	i = 0;
	while (rows)
	{
		map[i] = (char *)rows->content;
		rows = rows->next;
		i++;
	}
	map[i] = NULL;
}

typedef enum s_tiletype
{
    EMPTY = '0',
    WALL = '1',
    N = 'N',
    S = 'S',
    E = 'E',
    W = 'W';
} t_tiletype;

int valid_char(char c)
{
    if (c == WALL || c == EMPTY || c == N || c == S || c == E || c == W)
        return (1);
    return (0);
}

int	ft_check_proper_walls(char **map)
{
    int x;
	int y;

	x = 0;
	y = 0; 
	
	while (data->map[y])
	{
		while (data->map[y][x])
		{
			if(!valid_char(data->map[y][x]))
			{
				ft_printf("Error: Invalid map character");
				return 0;
			}
			//check walls
			if(data->map[0][x] != WALL || data ->map[y-1][x] != WALL || data->map[y][0] != WALL || data->map[y][x-1] != WALL)
			{
				ft_printf("Error: Map should be surrounded with walls");
				return 0;
			}
			x++;
		}
		y++;
	}
}
