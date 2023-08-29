/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:58:32 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/20 20:24:27 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAIN_H
# define FT_MAIN_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include "ft_data.h"
# include "ft_clean.h"
# include "ft_mlx.h"

void	ft_init(t_data **data);
void	ft_parsing(int argc, char **argv, t_data *my_data);
int		ft_rendering(t_data *data);
int		ft_handle_keypress(int keysym, t_data *data);
int		ft_handle_exit(t_data *data);

#endif