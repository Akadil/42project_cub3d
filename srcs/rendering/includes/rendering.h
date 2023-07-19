/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:09:38 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/19 13:48:38 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include "rendering_utils.h"
# include "mlx.h"
# include "struct_data.h"
# include <stdio.h>

void	ft_react_to_event(t_data *data);
void	ft_render_background(t_data *data, int color);
void	ft_render_projection(t_data *data);
void    ft_rendering_sprites(t_data *data);

#endif
