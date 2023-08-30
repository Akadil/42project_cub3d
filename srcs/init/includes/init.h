/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:51:45 by aseisenb          #+#    #+#             */
/*   Updated: 2023/08/30 18:00:13 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "libft.h"
# include "mlx.h"
# include "struct_data.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

int		init_game(t_data *data);
int		init_game2(t_data *data);
int		ft_get_image_addr(t_data *data);
int		ft_get_images(t_data *data);
void	ft_init_player_view(t_data *data);
void	ft_clean(t_data *data);
int		ft_init_map(t_list *rows, char **map);
void	ft_init_player(t_data *data, char p, int i, int j);

#endif
