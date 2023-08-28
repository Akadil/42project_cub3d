/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:17:37 by aseisenb          #+#    #+#             */
/*   Updated: 2023/08/28 18:33:30 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "struct_list.h"
#include "libft.h"
#include <stdlib.h>

int valid_char(char c);
int ft_find_largest_height(char **map);
int is_player(char c);
int	ft_check_proper_walls(char **map);
int ft_find_largest_width(t_list *rows);
void    ft_free_map(char **map);
int	ft_init_map(t_list *rows, char **map);
void    ft_init_player(t_data *data, char p, int i, int j);
int ft_check_player_existense(char **map, t_data *data);

/**
 * @brief       Parse and check the map
 */
int ft_parsing_map(t_list *rows, t_data *data)
{
    char    **map;

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

int ft_check_player_existense(char **map, t_data *data)
{
    int     i;
    int     j;

    i = 0;
    while (map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if(is_player(map[i][j]) == 0)
            {
                if(data->player.x != 0.0)
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

/**
 * @brief Initalize the position of the player
 */
void    ft_init_player(t_data *data, char p, int i, int j)
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

/** */
int	ft_init_map(t_list *rows, char **map)
{
	int	i;
    int j;
    int largest_width;

    largest_width = ft_find_largest_width(rows);
	i = 0;
	while (rows)
	{
        map[i] = (char *)ft_calloc(sizeof(char), largest_width + 1);
        if (!map[i])
            return (-1);     // Fix me!
        j = 0;
        while (((char *)rows->content)[j] && ((char *)rows->content)[j] != '\n')
        {
            map[i][j] = ((char *)rows->content)[j];
            j++;
        }
        ft_memset(map[i] + j, ' ', largest_width - j);      // CHeck for correctness
        map[i][j] = '\0';
		rows = rows->next;
        i++;
	}
	map[i] = NULL;
    return (0);
}

/** */
void    ft_free_map(char **map)
{
    int i;

    i = 0;
    while (map[i])
    {
        free (map[i]);
        i++;
    }
    free (map);
}

/** */
int ft_find_largest_width(t_list *rows)
{
    int largest;
    int len;

    largest = -1;
    while (rows)
    {
        len = ft_strlen((char *)rows->content);
        if (((char *)rows->content)[len - 1] == '\n')
            len--;
        if (len > largest)
            largest = len;
        rows = rows->next;
    }
    return (largest);
}

/**
 * @brief Check if the map is surrounded with walls
 */
int	ft_check_proper_walls(char **map)
{
    int i;
	int j;

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
                if(i == 0 || j == 0 || !map[i + 1] || !map[i][j + 1])
                    return (-1);
                else if(map[i][j + 1] == ' ' || map[i][j - 1] == ' ')
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

int is_player(char c)
{
    if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
        return (0);
    return (-1);
}

int ft_find_largest_height(char **map)
{
    int x;
    
    x = 0;
    while(map[x])
        x++;
    return (x);
}

int valid_char(char c)
{
    if (c == '1' || c == '0' || c == ' ')
        return (0);
    if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
        return (0);
    return (-1);
}
