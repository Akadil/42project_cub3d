/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:35:30 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/30 18:02:03 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing.h"

/*
	ft_fill_matrix() - Copy the data from t_list to my structure
*/
int	ft_fill_matrix(t_fdf *data, t_list *rows)
{
	char	**line;
	int		i;
	int		j;

	if (ft_init_matrix(data, rows) != 0)
		return (-1);
	i = 0;
	while (rows && i >= 0)
	{
		line = ft_split(rows->content, ' ');
		if (!line)
			return (-1);
		j = 0;
		while (j < data->mtrx.width)
		{
			data->mtrx.node[i][j].z = ft_atoi(line[j]);
			ft_set_z_maximas(data, i, j);
			data->mtrx.node[i][j].color = -1;
			j++;
		}
		ft_free_d_array_char(line);
		rows = rows->next;
		i++;
	}
	return (0);
}

int	ft_init_matrix(t_fdf *data, t_list *rows)
{
	int	i;
	int	j;

	ft_find_width(data, rows);
	data->mtrx.node = (t_node **)ft_calloc(sizeof(t_node *), data->mtrx.height);
	if (!data->mtrx.node)
		return (-1);
	i = -1;
	while (++i < data->mtrx.height)
	{
		data->mtrx.node[i] = (t_node *)ft_calloc(sizeof(t_node),
				data->mtrx.width);
		if (!data->mtrx.node[i])
			return (ft_free_node(data), -1);
		j = 0;
		while (j < data->mtrx.width)
		{
			data->mtrx.node[i][j].x = i - (float)(data->mtrx.height - 1) / 2;
			data->mtrx.node[i][j].y = j - (float)(data->mtrx.width - 1) / 2;
			j++;
		}
	}
	data->mtrx.z_max = -2147483648;
	data->mtrx.z_min = 2147483647;
	return (0);
}

void	ft_find_width(t_fdf *data, t_list *rows)
{
	char	*line;
	int		width;
	int		i;
	int		prev;

	i = 0;
	width = 0;
	prev = 1;
	line = rows->content;
	while (line[i])
	{
		if (line[i] == ' ' && prev == 0)
		{
			width++;
			prev = 1;
		}
		else if (line[i] != ' ')
			prev = 0;
		i++;
	}
	width++;
	data->mtrx.width = width;
}

void	ft_free_d_array_char(char **trash)
{
	int	i;

	i = 0;
	while (trash[i])
	{
		free(trash[i]);
		i++;
	}
	free(trash);
}

void	ft_set_z_maximas(t_fdf *data, int i, int j)
{
	if (data->mtrx.node[i][j].z > data->mtrx.z_max)
		data->mtrx.z_max = data->mtrx.node[i][j].z;
	if (data->mtrx.node[i][j].z < data->mtrx.z_min)
		data->mtrx.z_min = data->mtrx.node[i][j].z;
}
