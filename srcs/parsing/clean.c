/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:52:36 by aseisenb          #+#    #+#             */
/*   Updated: 2023/08/29 17:52:38 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_parsing.h"

void	ft_clean_textures(t_data *data)
{
	if (data->wall.north.name)
		free(data->wall.north.name);
	if (data->wall.south.name)
		free(data->wall.south.name);
	if (data->wall.west.name)
		free(data->wall.west.name);
	if (data->wall.east.name)
		free(data->wall.east.name);
	if (data->wall.floor.name)
		free(data->wall.floor.name);
	if (data->wall.ceil.name)
		free(data->wall.ceil.name);
}

void	ft_lstclear_alt(t_list **rows_texture, t_list **rows_map)
{
	ft_lstclear(rows_texture, &free);
	ft_lstclear(rows_map, &free);
}
