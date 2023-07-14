/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:17:47 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/14 18:11:49 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MAIN_H
# define FT_MAIN_H

# include <X11/X.h>
# include <X11/keysym.h>
# include <stdio.h>
# include "struct_data.h"
# include "mlx.h"

//void    ft_parsing_akadil(int argc, char **argv, t_data *data);
void    ft_preprocessing(int argc, char **argv, t_data *data);
int     ft_rendering(t_data *data);
int     ft_key_press(int keysym, t_data *data);
int     ft_key_release(int keysym, t_data *data);

#endif
