/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_args.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:47:12 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/13 19:51:39 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_APRSING_ARGS_H
# define FT_APRSING_ARGS_H

# include <fcntl.h>
# include "libft.h"
# include <stdlib.h>
# include <stdio.h>

int	    ft_check_args(int argc, char **argv);
t_list    *ft_get_rows(int fd);
int     ft_is_bad_row(char *str);
void    ft_skip_space(char *str);
void    ft_modify_row(char *str);


#endif
