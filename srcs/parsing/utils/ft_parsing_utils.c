/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:57:12 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/14 16:03:27 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include <stdio.h>

/*  1. Return the linked list from which map rows(rows_map) started  */
/*  2. Also, update the (t_list **)rows, so that it is not linked to */
/*      rows_map                                                     */
t_list  *ft_get_map_rows(t_list *rows)
{
    while (rows)
    {
        if (((char *)rows->content)[0] == '1')
            break ;
        else if (((char *)rows->content)[0] == '0')
            break ;
        else if (((char *)rows->content)[0] == ' ')
            break ;
        else if (((char *)rows->content)[0] == 'N')
            break ;
        else if (((char *)rows->content)[0] == 'S')
            break ;
        else if (((char *)rows->content)[0] == 'W')
            break ;
        else if (((char *)rows->content)[0] == 'E')
            break ;
        rows = rows->next;
    }
    if (!rows)
        return (NULL);
    rows->prev->next = NULL;
    rows->prev = NULL;
    return (rows);
}