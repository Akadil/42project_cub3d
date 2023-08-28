/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_projection.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 15:14:08 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/16 11:45:05 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RENDER_PROJECTION_H
# define FT_RENDER_PROJECTION_H

# include "ft_data.h"

void	ft_set_x_y(t_data *data);
void	ft_transform(t_data *data, int i, int j);
void	ft_draw_line(t_data *data, int i, int j, int direct);

#endif