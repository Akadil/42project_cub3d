/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:06:51 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/03 11:47:25 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/includes/ft_parsing.h"

/*  Parse and check the inputs, files, maps */
void    ft_parsing(int argc, char **argv, t_data *data)
{
    t_list  *rows;
    t_list  *rows_map;
    int     result;

    rows = NULL;

    /*  Parse the arguments and get the rows as a linked list   */
    /*  -----------------------------------------------------   */
    result = ft_parsing_args(argc, argv, &rows);
    if (result != 0)
        ft_error("Error!\n", result);

    /*  Get rows of map and unlink from the beginning   */
    rows_map = ft_get_map_rows(&rows);
    if (rows_map != 0)
        ft_error("Error!\n", -1);

    /*  Parse the texture   */
    /*  -----------------   */
    result = ft_parsing_textures(rows, data);
    if (result != 0)
        ft_error("Error!\n", result);
    
    /*  Parse the map   */
    /*  -------------   */
    result = ft_parsing_map(rows_map, data);
    if (result != 0)
        ft_error("Error!\n", result);
}   
