/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:14:59 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/05 11:29:44 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"
#include "struct_data.h"

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
	// mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &ft_handle_keypress, data);
	// mlx_hook(data.win_ptr, DestroyNotify, 0, &ft_handle_exit, data);
	mlx_loop(data.mlx_ptr);
	
	/*	Clean everything	*/
	// ft_clean(data);
    return (0);
}
