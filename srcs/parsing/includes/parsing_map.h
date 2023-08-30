/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:52:25 by aseisenb          #+#    #+#             */
/*   Updated: 2023/08/30 18:01:38 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_MAP_H
# define PARSING_MAP_H

# include "libft.h"
# include "struct_data.h"
# include "struct_list.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_init_map(t_list *rows, char **map);
int		ft_check_proper_walls(char **map);
int		ft_check_player_existense(char **map, t_data *data);
int		ft_find_largest_width(t_list *rows);
int		valid_char(char c);
int		is_player(char c);
void	ft_free_map(char **map);

#endif
