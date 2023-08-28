/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gm_fill_matrix.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:25:03 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/16 11:49:41 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GM_FILL_MATRIX_H
# define FT_GM_FILL_MATRIX_H

# include "ft_data.h"
# include "ft_libft.h"

void	ft_init_matrix(t_data *data, t_list *rows, int fd);
void	ft_find_width(t_data *data, t_list *rows);
void	ft_close_free_serror(t_data *trash, t_list *head, char *str, int fd);
int		hex_to_dec(char *hex_string);
void	ft_free_d_array_char(char **trash);
void	ft_set_z_maximas(t_data *data, int i, int j);

#endif