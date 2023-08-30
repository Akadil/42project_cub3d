/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/30 20:14:59 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/30 17:13:13 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_main.h"
#include "libft.h"
#include "struct_data.h"

int	main(int argc, char **argv)
{
	t_data	data;

	ft_memset(&data, '\0', sizeof(data));
	ft_parsing(argc, argv, &data);
	if (init_game(&data) != 0)
		return (ft_free_node(&data.fdf), ft_clean_textures(&data),
			ft_free_map(data.map), -1);
	mlx_mouse_move(data.mlx_ptr, data.win_ptr, WINDOW_WIDTH / 2, WINDOW_HEIGHT
		/ 2);
	mlx_mouse_hide(data.mlx_ptr, data.win_ptr);
	mlx_loop_hook(data.mlx_ptr, &ft_rendering, &data);
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &ft_key_press, &data);
	mlx_hook(data.win_ptr, KeyRelease, KeyReleaseMask, &ft_key_release, &data);
	mlx_hook(data.win_ptr, 6, 1L << 6, ft_mouse_move, &data);
	mlx_hook(data.win_ptr, DestroyNotify, 0, &ft_handle_exit, &data);
	mlx_loop(data.mlx_ptr);
	free(data.rays);
	ft_free_node(&data.fdf);
	ft_clean(&data);
	ft_clean_textures(&data);
	ft_free_map(data.map);
	return (0);
}

int	ft_handle_exit(t_data *data)
{
	free(data->rays);
	ft_free_node(&data->fdf);
	ft_clean(data);
	ft_clean_textures(data);
	ft_free_map(data->map);
	exit(-1);
	return (0);
}
