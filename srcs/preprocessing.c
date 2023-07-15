/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprocessing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:06:51 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/14 18:37:17 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing/includes/ft_parsing.h"

/*  Parse and check the inputs, files, maps */
void	ft_preprocessing(int argc, char **argv, t_data *data)
{
	t_list	*rows;
	t_list	*rows_map;
	int		result;

	rows = NULL;
	result = ft_parsing_args(argc, argv, &rows);
	if (result != 0)
		exit(-1);
	rows_map = ft_get_map_rows(&rows);
	if (!rows_map)
		exit(-1);
	result = ft_parsing_textures(rows, data);
	if (result != 0)
		ft_printf("Error!\n");


	result = ft_parsing_map(rows_map, data);
	if (result != 0)
		ft_printf("Error!\n");
	// Free everything!
}
