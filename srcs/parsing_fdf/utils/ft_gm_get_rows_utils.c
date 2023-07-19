/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gm_get_rows_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:11:50 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/16 16:13:31 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "ft_error.h"
#include "ft_libft.h"
#include <stdlib.h>

void	ft_close_clear_serror(t_data *_data, t_list *_head, int _fd)
{
	get_next_line(_fd, 1);
	close(_fd);
	ft_lstclear(&_head, &free);
	ft_strerror_clean_exit(_data, "Parsing the file");
}

void	ft_close_clear_merror(t_data *_data, t_list *_head, int _fd)
{
	get_next_line(_fd, 1);
	close(_fd);
	ft_lstclear(&_head, &free);
	ft_merror_clean_exit(_data, "The file is empty", NULL);
}
