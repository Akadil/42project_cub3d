/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_list.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 17:29:34 by akadilkalim       #+#    #+#             */
/*   Updated: 2023/08/30 17:59:48 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_LIST_H
# define STRUCT_LIST_H

typedef struct s_list
{
	char			*content;
	int				type;
	struct s_list	*next;
	struct s_list	*prev;
}					t_list;

#endif
