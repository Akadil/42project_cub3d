/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:57:12 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/03 11:05:26 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"

/*  1. Return the linked list from which map rows(rows_map) started  */
/*  2. Also, update the (t_list **)rows, so that it is not linked to */
/*      rows_map                                                     */
t_list  *ft_get_map_rows(t_list **rows);