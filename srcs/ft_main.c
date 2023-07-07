/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:14:59 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/07 15:31:22 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"
#include "struct_data.h"

int	ft_handle_keypress(int keysym, t_data *data)
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
	else if (keysym == 'w')
    {
		if(data->map[(int)(data->player.y)][(int)(data->player.x + data->view.dir.x * 0.05)] != '1') 
			data->player.x = data->player.x + data->view.dir.x * 0.05;
		if(data->map[(int)(data->player.y + data->view.dir.y * 0.05)][(int)(data->player.x)] != '1') 
			data->player.y += data->view.dir.y * 0.05;
    }
    //move backwards if no wall behind you
    else if (keysym == 's')
    {
		if(data->map[(int)(data->player.y)][(int)(data->player.x - data->view.dir.x * 0.05)] != '1') 
			data->player.x -= data->view.dir.x * 0.05;
		if(data->map[(int)(data->player.y - data->view.dir.y * 0.05)][(int)(data->player.x)] != '1') 
			data->player.y -= data->view.dir.y * 0.05;
    }
	else if (keysym == 'a')
    {
		if(data->map[(int)(data->player.y)][(int)(data->player.x - data->view.plane.x * 0.1)] != '1') 
			data->player.x -= data->view.plane.x * 0.1;
		if(data->map[(int)(data->player.y - data->view.plane.y * 0.1)][(int)(data->player.x)] != '1') 
			data->player.y -= data->view.plane.y * 0.1;
    }
	else if (keysym == 'd')
    {
		if(data->map[(int)(data->player.y)][(int)(data->player.x + data->view.plane.x * 0.1)] != '1') 
			data->player.x += data->view.plane.x * 0.1;
		if(data->map[(int)(data->player.y + data->view.plane.y * 0.1)][(int)(data->player.x)] != '1') 
			data->player.y += data->view.plane.y * 0.1;
    }
	return (0);
}

int main(int argc, char **argv)
{
    t_data	data;

	/*	Parse and check the map	*/
	// ft_parsing(argc, **argv, &data);

	/*	Initialize the map	*/
	// init_game(&data, argv[1]);
	
	ft_parsing_akadil(argc, argv, &data);

	/*	Start rendering	*/
	mlx_loop_hook(data.mlx_ptr, &ft_rendering, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &ft_handle_keypress, &data);
	// mlx_hook(data.win_ptr, DestroyNotify, 0, &ft_handle_exit, data);
	mlx_loop(data.mlx_ptr);
	
	/*	Clean everything	*/
	// ft_clean(data);
    return (0);
}
