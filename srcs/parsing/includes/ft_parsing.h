/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:43:56 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/28 13:38:30 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSING_H
# define FT_PARSING_H

#include "struct_data.h"
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

int		ft_parsing_args(int argc, char **argv, t_list **rows);
t_list	*ft_get_map_rows(t_list **rows);
int		ft_parsing_textures(t_list *rows, t_data *data);
int		ft_parsing_map(t_list *rows, t_data *data);

int	check_valid_rgb(char *str);
int	set_rgb_colors(char *str);
int	ft_check_proper_walls(char **map, t_data *data);
int ft_find_largest_height(char **map);

int ft_check_file_existence_wall(t_data *data);
void    ft_check_direction_names(t_list *head, t_data *data);

#endif