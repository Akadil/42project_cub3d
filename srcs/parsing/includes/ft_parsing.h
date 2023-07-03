/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:43:56 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/03 11:10:41 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSING_H
# define FT_PARSING_H

# include "struct_data.h"
# include "struct_list.h"
# include <stdio.h>

int		ft_parsing_args(int argc, char **argv, t_list **rows);
t_list	*ft_get_map_rows(t_list **rows);
int		ft_parsing_textures(t_list *rows);
int		ft_parsing_map(t_list *rows);

#endif