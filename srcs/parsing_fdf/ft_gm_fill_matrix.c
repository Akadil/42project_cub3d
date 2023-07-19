/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gm_fill_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 13:28:51 by akalimol          #+#    #+#             */
/*   Updated: 2023/06/29 17:24:39 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_gm_fill_matrix.h"

void	ft_fill_matrix(t_data *data, t_list *rows, int fd)
{
	char	**line;
	int		i;
	int		j;

	ft_init_matrix(data, rows, fd);
	i = -1;
	while (rows && ++i >= 0)
	{
		line = ft_split(rows->content, ' ');
		if (!line)
			ft_close_free_serror(data, rows, "Line separation", fd);
		j = -1;
		while (++j < data->mtrx.width)
		{
			data->mtrx.node[i][j].z = ft_atoi(line[j]);
			ft_set_z_maximas(data, i, j);
			if (ft_strchr(line[j], ','))
				data->mtrx.node[i][j].color = hex_to_dec(ft_strchr(line[j], ',') + 1);
			else
				data->mtrx.node[i][j].color = -1;
		}
		ft_free_d_array_char(line);
		rows = rows->next;
	}
}

void	ft_init_matrix(t_data *data, t_list *rows, int fd)
{
	t_node	**node;
	int		i;
	int		j;

	ft_find_width(data, rows);
	node = (t_node **)malloc(sizeof(t_node *) * data->mtrx.height);
	if (!node)
		ft_close_free_serror(data, rows, "Matrix creation", fd);
	i = -1;
	while (++i < data->mtrx.height)
	{
		node[i] = (t_node *)malloc(sizeof(t_node) * data->mtrx.width);
		if (!node[i])
			ft_close_free_serror(data, rows, "Matrix creation", fd);
		j = 0;
		while (j < data->mtrx.width)
		{
			node[i][j].x = i - (float)(data->mtrx.height - 1) / 2;
			node[i][j].y = j - (float)(data->mtrx.width - 1) / 2;
			j++;
		}
	}
	data->mtrx.node = node;
	data->mtrx.z_max = -2147483648;
	data->mtrx.z_min = 2147483647;
}
