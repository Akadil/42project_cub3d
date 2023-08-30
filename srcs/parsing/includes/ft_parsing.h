/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:43:56 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/30 18:01:29 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSING_H
# define FT_PARSING_H

# include "libft.h"
# include "mlx.h"
# include "struct_data.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_parsing_args(int argc, char **argv, t_list **rows);
int		ft_get_map_rows(t_list **head, t_list **rows_map);
int		ft_parsing_textures(t_list *rows, t_data *data);
int		ft_parsing_map(t_list *rows, t_data *data);
int		ft_parsing_fdf(t_data *data);
void	ft_unbound(t_list **row);
void	ft_lstclear_alt(t_list **rows_texture, t_list **rows_map);
t_list	*ft_get_rows_fd(t_fdf *data, int fd);
int		ft_fill_matrix(t_fdf *data, t_list *rows);
void	ft_clean_textures(t_data *data);
int		ft_init_matrix(t_fdf *data, t_list *rows);
void	ft_set_z_maximas(t_fdf *data, int i, int j);
void	ft_free_d_array_char(char **trash);
void	ft_find_width(t_fdf *data, t_list *rows);
void	ft_free_node(t_fdf *trash);

#endif