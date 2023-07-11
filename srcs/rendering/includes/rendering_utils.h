/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 12:10:14 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/11 12:14:40 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_UTILS_H
# define RENDERING_UTILS_H

# include "struct_data.h"

int     create_rgb(int r, int g, int b);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif
