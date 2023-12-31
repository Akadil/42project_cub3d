/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_matrix.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 18:31:02 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/24 16:13:21 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GET_MATRIX_H
# define FT_GET_MATRIX_H

# include "ft_data.h"
# include "ft_error.h"
# include "ft_libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

int		my_open(t_data *_my_data, char **_argv);
t_list	*ft_get_rows(t_data *data, int fd);
void	ft_init_matrix(t_data *data, t_list *rows, int fd);
void	ft_fill_matrix(t_data *data, t_list *head, int fd);
void	ft_find_width(t_data *data, t_list *rows);
void	ft_close_free_serror(t_data *trash, t_list *head, char *str, int fd);
int		hex_to_dec(char *hex_string);
void	ft_free_d_array_char(char **trash);
void	ft_set_z_maximas(t_data *data, int i, int j);

#endif