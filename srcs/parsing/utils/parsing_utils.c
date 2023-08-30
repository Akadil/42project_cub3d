/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:09:38 by aseisenb          #+#    #+#             */
/*   Updated: 2023/08/30 18:15:20 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"
#include "libft.h"
#include "struct_list.h"
#include <stdio.h>

void	ft_unbound(t_list **row)
{
	(*row)->prev->next = NULL;
	(*row)->prev = NULL;
}

int	ft_get_map_rows(t_list **head, t_list **rows_map)
{
	t_list	*rows;

	rows = *head;
	while (rows)
	{
		if ((rows->content)[0] == '1')
			break ;
		else if ((rows->content)[0] == '0')
			break ;
		else if ((rows->content)[0] == 'N' && (rows->content)[1] != 'O')
			break ;
		else if ((rows->content)[0] == 'S' && (rows->content)[1] != 'O')
			break ;
		else if ((rows->content)[0] == 'W' && (rows->content)[1] != 'E')
			break ;
		else if ((rows->content)[0] == 'E' && (rows->content)[1] != 'A')
			break ;
		rows = rows->next;
	}
	if (!rows)
		return (ft_putstr_fd("Map doesn't exist!\n", 2), -1);
	if (!rows->prev)
		return (ft_putstr_fd("Configuration doesn't exist\n", 2), -1);
	ft_unbound(&rows);
	*rows_map = rows;
	return (0);
}
