/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rendering.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 14:52:47 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/16 17:07:33 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RENDERING_H
# define FT_RENDERING_H

# include <stdio.h>
# include "ft_data.h"
# include "ft_error.h"
# include "ft_mlx.h"

void	ft_render_background(t_data *data, int color);
void	ft_render_projection(t_data *data);

#endif