/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gm_fill_matrix_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 20:23:38 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/16 16:04:06 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "ft_error.h"
#include "ft_libft.h"
#include <stdlib.h>

void	ft_find_width(t_data *data, t_list *rows)
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

int	hex_to_dec(char *hex_string)
{
	int		decimal_value;
	int		i;
	int		digit_value;
	char	c;

	decimal_value = 0;
	i = 0;
	while (hex_string[i] != '\0')
	{
		c = hex_string[i];
		if (c >= '0' && c <= '9')
			digit_value = c - '0';
		else if (c >= 'A' && c <= 'F')
			digit_value = c - 'A' + 10;
		else if (c >= 'a' && c <= 'f')
			digit_value = c - 'a' + 10;
		decimal_value = decimal_value * 16 + digit_value;
		i++;
	}
	return (decimal_value);
}

void	ft_close_free_serror(t_data *trash, t_list *head, char *str, int fd)
{
	close(fd);
	ft_lstclear(&head, &free);
	ft_strerror_clean_exit(trash, str);
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

void	ft_set_z_maximas(t_data *data, int i, int j)
{
	if (data->mtrx.node[i][j].z > data->mtrx.z_max)
		data->mtrx.z_max = data->mtrx.node[i][j].z;
	if (data->mtrx.node[i][j].z < data->mtrx.z_min)
		data->mtrx.z_min = data->mtrx.node[i][j].z;
}
