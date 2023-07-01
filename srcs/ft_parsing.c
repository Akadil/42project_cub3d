/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:06:51 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/01 14:48:16 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "struct_list.h"

void    ft_parsing(int argc, char **argv, t_data *data)
{
    t_list  *rows;
    int     fd;

    fd = ft_parsing_args(argc, argv);
}

/*  Functions to write  */

/**
 * @brief       Check the arguments and file existence
 * 
 * @details     The name of the file (argv[1]) could be wrongly formatted. Check
 *              for proper name. check if it exists, and return fd (int) value 
 *              if exists 
 * 
 * @return int  -   if everything is ok, return fd of the file
 */
int ft_parsing_args(int argc, char **argv);
