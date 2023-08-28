/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:17:00 by aseisenb          #+#    #+#             */
/*   Updated: 2023/07/14 18:36:52 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_parsing.h"
#include "libft.h"
#include "struct_data.h"
#include "struct_list.h"
#include <stdlib.h>

int	ft_rgb_end(char *str, int i, int k)
{
	if (str[i] != ',' || k == 3)
	{
		if (k == 3 && str[i] == '\0')
			return (0);
		return (1);
	}
	return (0);
}

int	ft_check_rgbformat(char *str, int i)
{
	int	j;
	int	k;

	k = 0;
	while (str[i])
	{
		j = 0;
		while (ft_isdigit(str[i]))
		{
			j++;
			i++;
		}
		if (j == 0)
			return (1);
		k++;
		if (ft_rgb_end(str, i, k))
			return (1);
		i++;
	}
	if (k != 3)
		return (1);
	return (0);
}

int	check_valid_rgb(char *str)
{
	int	i;
	int	value;

	i = 0;
	if (ft_check_rgbformat(str, i))
		return (1);
	while (i < 3)
	{
		value = ft_atoi(str);
		if (value < 0 || value > 255)
			return (1);
		while (*str != ',' && *str)
			str++;
		str++;
		i++;
	}
	return (0);
}

int	create_rgb_2(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	set_rgb_colors(char *str)
{
	int	r;
	int	g;
	int	b;

	r = ft_atoi(str);
	str = ft_strchr(str, ',') + 1;
	g = ft_atoi(str);
	str = ft_strchr(str, ',') + 1;
	b = ft_atoi(str);
	return (create_rgb_2(r, g, b));
}
