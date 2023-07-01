/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:14:59 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/01 14:05:35 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"

int main(int argc, char **argv)
{
    t_data	data;

	data = NULL;
	ft_parsing(argc, **argv);
	init_game(&data, argv[1]);
//	if (!valid_file(&data, argv[1]))
//		exit_game(&data);
	mlx_loop_hook(data->mlx_ptr, &ft_rendering, data);
	mlx_hook(data->win_ptr, KeyPress, KeyPressMask, &ft_handle_keypress, data);
	mlx_hook(data->win_ptr, DestroyNotify, 0, &ft_handle_exit, data);
	mlx_loop(data->mlx_ptr);
	ft_clean(data);
    return (0);
}
