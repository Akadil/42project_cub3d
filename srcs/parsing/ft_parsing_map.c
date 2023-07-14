/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 12:34:55 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/12 16:45:54 by akalimol         ###   ########.fr       */
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

    if (ft_check_player_existense(rows, data) != 0)
        return (-1);
    map = (char **)malloc(sizeof(char *) * (ft_lstsize(rows) + 1));
    if (!map)
        return (ft_lstclear(&rows, &free), -1);
    ft_init_map(rows, map);
    ft_lstclear(&rows, NULL);
	if (ft_check_proper_walls(map) != 0)
        return (-1);
    data->map = map;
    return (0);
}

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
