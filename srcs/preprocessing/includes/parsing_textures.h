/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:27:41 by aseisenb          #+#    #+#             */
/*   Updated: 2023/07/14 18:36:37 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_TEXTURES_H
# define PARSING_TEXTURES_H

# include "struct_data.h"
# include "struct_list.h"
# include <fcntl.h>

void	ft_check_direction_names(t_list *head, t_data *data);
int	ft_check_file_existence_wall(t_data *data);
int	ft_is_wall(t_data *data, char *content);
int	ft_is_ceil_floor(t_data *data, char *content);
void	ft_assign_names_wall(t_data *data, t_list *row);
void	ft_assign_names_floor_ceil(t_data *data, t_list *row);
int	check_valid_rgb(char *str);
int	set_rgb_colors(char *str);

#endif
