/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_rows_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:21:45 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/30 18:02:15 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "struct_data.h"
#include <stdio.h>

/*
	Goal: Retrieve the row strings from the file and save it in linked list
*/
t_list	*ft_get_rows_fd(t_fdf *data, int fd)
{
	t_list	*head;
	t_list	*temp;
	char	*str;

	head = NULL;
	str = get_next_line(fd, 0);
	while (str)
	{
		temp = ft_lstnew(str, 0);
		if (!temp)
			return (ft_lstclear(&head, &free), NULL);
		ft_lstadd_back(&head, temp);
		str = get_next_line(fd, 0);
	}
	get_next_line(fd, 1);
	if (!head)
		return (NULL);
	data->mtrx.height = ft_lstsize(head);
	return (head);
}

void	ft_free_node(t_fdf *trash)
{
	int	i;

	i = 0;
	if (!trash)
		return ;
	if (trash->mtrx.node)
	{
		while (i < trash->mtrx.height && trash->mtrx.node[i])
		{
			free(trash->mtrx.node[i]);
			i++;
		}
		free(trash->mtrx.node);
	}
}
