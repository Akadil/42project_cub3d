/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gm_get_rows.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 12:21:45 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/11 20:22:56 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_gm_get_rows.h"

/*
    Goal: Retrieve the row strings from the file and save it in linked list
*/
t_list	*ft_get_rows(t_data *data, int fd)
{
	t_list	*head;
	t_list	*temp;
	char	*str;

	head = NULL;
	str = get_next_line(fd, 0);
	while (str)
	{
		temp = ft_lstnew(str);
		if (!temp)
			ft_close_clear_serror(data, head, fd);
		ft_lstadd_back(&head, temp);
		str = get_next_line(fd, 0);
	}
	get_next_line(fd, 1);
	if (!head)
		ft_close_clear_merror(data, head, fd);
	data->mtrx.height = ft_lstsize(head);
	return (head);
}
