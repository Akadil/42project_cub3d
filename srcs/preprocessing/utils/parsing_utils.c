/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:09:38 by aseisenb          #+#    #+#             */
/*   Updated: 2023/07/14 18:23:18 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct_list.h"

void	ft_unbound(t_list *row);

t_list	*ft_get_map_rows(t_list *rows)
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
	{
		ft_printf2("Map doesn't exist!\n");
		return (ft_lstclear(rows, &free), NULL);
	}
	ft_unbound(rows);
	return (rows);
}

void	ft_unbound(t_list *row)
{
	row->prev->next = NULL;
	row->prev = NULL;
}
