/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_textures.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 18:27:41 by aseisenb          #+#    #+#             */
/*   Updated: 2023/08/30 18:01:48 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_TEXTURES_H
# define PARSING_TEXTURES_H

# include "ft_parsing.h"
# include "libft.h"
# include "struct_data.h"
# include "struct_list.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_check_texture_names(t_list *rows, t_data *data);
int		ft_check_file_existence_wall(t_data *data);
int		ft_is_wall(t_data *data, char *content);
void	ft_assign_names_wall(t_data *data, char *content);
int		ft_is_ceil_floor(t_data *data, char *content);
void	ft_assign_names_floor_ceil(t_data *data, char *content);
int		check_valid_rgb(char *str);
int		set_rgb_colors(char *str);
int		ft_rgb_end(char *str, int i, int k);
int		ft_check_rgbformat(char *str, int i);
int		create_rgb_2(int r, int g, int b);

#endif
