/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_args.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:47:12 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/30 18:12:54 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSING_ARGS_H
# define FT_PARSING_ARGS_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_check_args(int argc, char **argv);
t_list	*ft_get_rows(int fd);
int		ft_is_bad_row(char *str);
void	ft_skip_space(char *str);
void	ft_modify_row(char *str);

#endif
