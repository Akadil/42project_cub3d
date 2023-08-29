/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:17:47 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/29 19:23:50 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAIN_H
# define FT_MAIN_H

# include "mlx.h"
# include "struct_data.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>

void	ft_parsing(int argc, char **argv, t_data *data);
int		init_game(t_data *data);
void	ft_free_map(char **map);
int		ft_rendering(t_data *data);
int		ft_key_press(int keysym, t_data *data);
int		ft_key_release(int keysym, t_data *data);
int		ft_mouse_move(int x, int y, t_data *data);
void	ft_clean_textures(t_data *data);
void	ft_clean(t_data *data);
void	ft_free_node(t_fdf *trash);
int		ft_handle_exit(t_data *data);

#endif
