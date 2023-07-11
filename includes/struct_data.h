/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_data.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:19:18 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/11 15:36:20 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_DATA_H
# define STRUCT_DATA_H

# define WINDOW_HEIGHT 480
# define WINDOW_WIDTH 640
# define SPEED 0.07
# define ROTATION 3

typedef struct s_vector
{
    double  x;
    double  y;
}   t_vector;

typedef struct s_img
{
	void		*mlx_img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
	int			width;
	int			height;
}				t_img;

typedef struct s_wall
{
    t_img    north;
    t_img    south;
    t_img    west;
    t_img    east;
    void    *floor;
    void    *ceil;
}   t_wall;

typedef struct s_view
{
    t_vector    dir;
    t_vector    plane;   
}       t_view;

#include <stdbool.h>

typedef struct s_event
{
	bool	move_fw;
	bool	move_bw;
	bool	move_rg;
	bool	move_lf;
	bool	rotate_lf;
	bool	rotate_rg;
}	t_event;


/*  Our main data   */
typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img_win;
	t_img		img_minimap;

	char		**map;

	t_wall		wall;
	t_event		event;
	t_vector	player;
	t_view		view;
	float		angle;
}   			t_data;

#endif
