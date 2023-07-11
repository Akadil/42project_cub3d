/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:45:38 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/11 12:34:53 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "struct_data.h"
# include <X11/X.h>
# include <X11/keysym.h>
#include <stdio.h>

void    ft_keypress_movement_right_left(int keysym, t_data *data);
void    ft_keypress_movement_up_down(int keysym, t_data *data);
void    ft_keypress_movement(int keysym, t_data *data);

int	ft_keypress(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		data->win_ptr = NULL;
	}
	else if (keysym == 'j')
	{
		if (data->angle == 355)
			data->angle = 0;
		else
			data->angle += 5;
	}
	else if (keysym == 'h')
	{
		if (data->angle == 0)
			data->angle = 355;
		else
			data->angle -= 5;
	}
    else if (keysym == 'w' || keysym == 's' || keysym == 'a' || keysym == 'd')
        ft_keypress_movement(keysym, data);
    return (0);
}

void    ft_keypress_movement(int keysym, t_data *data)
{
    if (keysym == 'w' || keysym == 's')
        ft_keypress_movement_up_down(keysym, data);
    else
        ft_keypress_movement_right_left(keysym, data);	
}

void    ft_keypress_movement_up_down(int keysym, t_data *data)
{
    int x_pos;
    int y_pos;
    double x_pos_new;
    double y_pos_new;

    x_pos = (int)(data->player.x);
    y_pos = (int)(data->player.y);
    if (keysym == 'w')
    {
        x_pos_new = data->player.x + data->view.dir.x * SPEED;
		if(data->map[y_pos][(int)(x_pos_new)] != '1') 
			data->player.x = x_pos_new;
        y_pos_new = data->player.y + data->view.dir.y * SPEED;
		if(data->map[(int)(y_pos_new)][x_pos] != '1') 
			data->player.y = y_pos_new;
    }
    else
    {
        x_pos_new = data->player.x - data->view.dir.x * SPEED;
		if(data->map[y_pos][(int)(x_pos_new)] != '1') 
			data->player.x = x_pos_new;
        y_pos_new = data->player.y - data->view.dir.y * SPEED;
		if(data->map[(int)(y_pos_new)][x_pos] != '1') 
			data->player.y = y_pos_new;
    }
}

void    ft_keypress_movement_right_left(int keysym, t_data *data)
{
    int x_pos;
    int y_pos;
    double x_pos_new;
    double y_pos_new;

    x_pos = (int)(data->player.x);
    y_pos = (int)(data->player.y);
    if (keysym == 'a')
    {
        x_pos_new = data->player.x - data->view.plane.x * SPEED;
		if(data->map[y_pos][(int)(x_pos_new)] != '1') 
			data->player.x = x_pos_new;
        y_pos_new = data->player.y - data->view.plane.y * SPEED;
		if(data->map[(int)(y_pos_new)][x_pos] != '1') 
			data->player.y = y_pos_new;
    }
	else
    {
        x_pos_new = data->player.x + data->view.plane.x * SPEED;
		if(data->map[y_pos][(int)(x_pos_new)] != '1') 
			data->player.x = x_pos_new;
        y_pos_new = data->player.y + data->view.plane.y * SPEED;
		if(data->map[(int)(y_pos_new)][x_pos] != '1') 
			data->player.y = y_pos_new;
    }
}