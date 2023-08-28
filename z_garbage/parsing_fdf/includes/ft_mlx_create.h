/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mlx_create.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 15:05:37 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/11 20:42:31 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MLX_CREATE_H
# define FT_MLX_CREATE_H

# include "ft_data.h"
# include "ft_mlx.h"
# include "ft_error.h"
# include <stdio.h>

void	*my_mlx_init(t_data *data);
void	*my_mlx_new_window(t_data *data, char *name);
void	*my_mlx_new_image(t_data *data);
char	*my_mlx_get_data_addr(t_data *data);

#endif