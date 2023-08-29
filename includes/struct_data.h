/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_data.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:19:18 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/29 19:25:33 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_DATA_H
# define STRUCT_DATA_H

# define WINDOW_HEIGHT 480
# define WINDOW_WIDTH 640
# define SPEED 0.03
# define ROTATION 0.2
# define PI 3.14
# include <stdbool.h>

typedef struct s_img
{
	void			*mlx_img;
	char			*name;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct s_node
{
	float			x;
	float			y;
	int				z;
	int				color;
	int				x_p;
	int				y_p;
}					t_node;

typedef struct s_matrix
{
	t_node			**node;
	int				height;
	int				width;
	int				z_max;
	int				z_min;
}					t_matrix;

typedef struct s_param
{
	int				alpha;
	int				beta;
	int				theta;
	double			grid;
	double			attitude;
	int				x_offset;
	int				y_offset;
	int				color;
}					t_param;

typedef struct s_vector
{
	double			x;
	double			y;
}					t_vector;

typedef struct s_fdf
{
	t_img			img;
	t_matrix		mtrx;
	t_param			param;
	double			length;
	t_vector		pos;
	t_vector		pos_p;
}					t_fdf;

typedef struct s_color
{
	int				r;
	int				g;
	int				b;
}					t_color;

typedef struct s_coordinate
{
	int				x;
	int				y;
}					t_coorddinate;

typedef struct s_floor_ceil
{
	char			*name;
	int				color;
}					t_floor_ceil;

typedef struct s_wall
{
	t_img			north;
	t_img			south;
	t_img			west;
	t_img			east;
	t_floor_ceil	floor;
	t_floor_ceil	ceil;
}					t_wall;

typedef struct s_view
{
	t_vector		dir;
	t_vector		plane;
}					t_view;

typedef struct s_event
{
	bool			move_fw;
	bool			move_bw;
	bool			move_rg;
	bool			move_lf;
	bool			rotate_lf;
	bool			rotate_rg;
	int				rotation_speed;
	int				rotate_rg_mouse;
	int				rotate_lf_mouse;
}					t_event;

/*  Our main data   */
typedef struct s_data
{
	void			*mlx_ptr;
	void			*win_ptr;
	t_img			img_win;
	t_img			sprite;

	char			**map;
	double			*rays;

	t_fdf			fdf;
	t_wall			wall;
	t_event			event;
	t_vector		player;
	t_vector		sprite_pos;
	t_view			view;
	double			angle;
}					t_data;

typedef struct s_point
{
	int				i;
	int				j;
	int				color;
	int				x_p;
	int				y_p;
}					t_point;

typedef struct s_draw
{
	int				lineHeight;
	int				draw_start;
	int				draw_end;

	float			ratio_x;
	float			ratio_y;
	int				pos_x;
	int				pos_y;

	int				x;
	int				pos_color;
	int				r;
	int				g;
	int				b;
}					t_draw;

#endif
