/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:06:51 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/30 18:00:04 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"

/*  Parse and check the inputs, files, maps */
int	ft_parsing(int argc, char **argv, t_data *data)
{
	t_list	*rows_texture;
	t_list	*rows_map;

	rows_texture = NULL;
	rows_map = NULL;
	if (ft_parsing_args(argc, argv, &rows_texture) != 0)
		return (exit(-1), -1);
	if (ft_get_map_rows(&rows_texture, &rows_map) != 0)
		return (ft_lstclear(&rows_texture, &free), exit(-1), -1);
	if (ft_parsing_textures(rows_texture, data) != 0)
		return (ft_clean_textures(data), ft_lstclear_alt(&rows_texture,
				&rows_map), exit(-1), -1);
	ft_lstclear(&rows_texture, &free);
	if (ft_parsing_map(rows_map, data) != 0)
		return (ft_clean_textures(data), ft_lstclear(&rows_map, &free),
			exit(-1), -1);
	ft_lstclear(&rows_map, &free);
	ft_parsing_fdf(data);
	return (0);
}
