/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:19:47 by aseisenb          #+#    #+#             */
/*   Updated: 2023/08/29 17:45:28 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_parsing_args.h"

int	ft_isspace_alt(char c)
{
	if (c == ' ' || c == '\f')
		return (0);
	if (c == '\r' || c == '\t' || c == '\v')
		return (0);
	return (-1);
}

int	ft_is_bad_row(char *str)
{
	int	i;

	i = 0;
	while (str[i] && ft_isspace(str[i]) == 1)
		i++;
	if (str[i] == '\0' || str[i] == '\n')
		return (-1);
	return (0);
}

void	ft_skip_space(char *str)
{
	int	i;
	int	len;

	i = 0;
	while (str[i] && ft_isspace_alt(str[i]) == 0)
		i++;
	len = ft_strlcpy(str, str + i, ft_strlen(str) + 1);
	i = 0;
	while (str[len + i])
	{
		str[len + i] = '\0';
		i++;
	}
}

void	ft_modify_row(char *str)
{
	int	i;
	int	j;

	ft_skip_space(str);
	i = 0;
	while (str[i] && ft_isspace_alt(str[i]) != 0)
		i++;
	i++;
	ft_skip_space(str + i);
	j = 0;
	while ((str + i)[j] && ft_isspace_alt((str + i)[j]) != 0)
		j++;
	ft_skip_space(str + i + j);
}
