/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_fdf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:54:12 by aseisenb          #+#    #+#             */
/*   Updated: 2023/08/29 17:54:13 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_parsing.h"
#include "includes/parsing_map.h"

int	ft_parsing_fdf(t_data *data)
{
	t_list	*rows;
	int		fd;

	fd = open("fdf_maps/42.fdf", O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("FDF fail", 2), ft_clean_textures(data),
			ft_free_map(data->map), exit(-1), -1);
	rows = ft_get_rows_fd(&data->fdf, fd);
	if (!rows)
		return (ft_putstr_fd("Malloc fail", 2), ft_clean_textures(data),
			ft_free_map(data->map), exit(-1), -1);
	close(fd);
	if (ft_fill_matrix(&data->fdf, rows) != 0)
	{
		ft_putstr_fd("Malloc fail", 2);
		ft_free_map(data->map);
		ft_lstclear(&rows, &free);
		ft_clean_textures(data);
		return (exit(-1), -1);
	}
	ft_lstclear(&rows, &free);
	data->fdf.param.theta = 0;
	return (0);
}
