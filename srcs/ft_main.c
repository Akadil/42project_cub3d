/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:14:59 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/30 20:19:01 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

int main(int argc, char **argv)
{
    t_data	*my_data;

	my_data = NULL;
	ft_init(&my_data);
	ft_parsing(argc, argv, my_data);
	
	mlx_loop_hook(my_data->mlx_ptr, &ft_rendering, my_data);
	mlx_hook(my_data->win_ptr, KeyPress, KeyPressMask, &ft_handle_keypress, my_data);
	mlx_hook(my_data->win_ptr, DestroyNotify, 0, &ft_handle_exit, my_data);
	mlx_loop(my_data->mlx_ptr);
	ft_clean(my_data);
    return (0);
}