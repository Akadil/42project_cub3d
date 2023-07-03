/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_data.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:19:18 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/03 10:50:34 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_DATA_H
# define STRUCT_DATA_H

/*  Our main data   */
typedef struct s_data
{
    void    *mlx_ptr;
    void    *win_ptr;
	t_wall	*wall;
	char	**map;
}   t_data;

typedef struct s_wall
{
    void    *north;
    void    *south;
    void    *west;
    void    *east;
    void    *floor;
    void    *ceil;
}   t_wall;

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;

#endif
