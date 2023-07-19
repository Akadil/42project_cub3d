/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_fdf.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 11:57:14 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/18 16:34:31 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DATA_H
# define FT_DATA_H

// # define WINDOW_WIDTH 500
// # define WINDOW_HEIGHT 500
// # define WINDOW_WIDTH 1920
// # define WINDOW_HEIGHT 1080
# define RED_PIXEL 0xFF0000
# define GREEN_PIXEL 0xFF00
# define BLUE_PIXEL 0xFF
# define WHITE_PIXEL 0xFFFFFF

# include "struct_data.h"

/*
	Node is a one point of the map

	x, y, z 	- its coordinate
	color		- point color
	x_p, y_p	- position after transformation
*/
typedef struct s_node
{
	float		x;
	float		y;
	int			z;
	int			color;
	int			x_p;
	int			y_p;
}				t_node;

typedef struct s_matrix
{
	t_node		**node;
	int			height;
	int			width;
	int			z_max;
	int			z_min;
}				t_matrix;

typedef struct s_param
{
	int			alpha;
	int			beta;
	int			theta;
	int			grid;
	int			attitude;
	int			x_offset;
	int			y_offset;
	int			color;
}				t_param;

typedef struct s_fdf
{
	t_img		img;
	t_matrix	mtrx;
	t_param		param;
}				t_fdf;

#endif