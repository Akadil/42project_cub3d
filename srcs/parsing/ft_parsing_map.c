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
int ft_parsing_map(t_list *rows)
{
    char    **map;
    int     i;

    if (ft_lstsize(rows) <= 2)
        return (-1);
    if (ft_check_player_existense(rows) != 0)
        return (-1);
    if (ft_check_proper_walls(rows) != 0)
        return (-1);
    map = (char **)malloc(sizeof(char *) * (ft_lstsize(rows) + 1));
    if (!map)
        return (-1);
    
    /*  Assign the values */
    ft_assign_values(rows, map);

    /*  As we already parsed everything, we can free the row lists  */
    ft_clean_rows(rows);

    /*  Find player and assign his values to data->player   */
    ft_find_player(map);
}