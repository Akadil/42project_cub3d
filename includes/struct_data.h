/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_data.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:19:18 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/04 10:50:45 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_DATA_H
# define STRUCT_DATA_H

/*  Our main data   */
typedef struct s_data
{
	/*	Access to mlx instances*/
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img_win;
	t_img		img_minimap;

	/*	The map	*/
	char		**map;

	/*	Wall textures	*/
	t_wall		*wall;

	t_position	*player;
	t_position	*ray;
}   			t_data;

typedef struct s_position
{
	int	x;
	int	y;
	int	a;
}	t_position;

typedef struct s_wall
{
    t_img    *north;
    t_img    *south;
    t_img    *west;
    t_img    *east;
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
