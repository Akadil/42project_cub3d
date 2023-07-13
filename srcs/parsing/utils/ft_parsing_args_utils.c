/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_args_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:48:56 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/13 19:51:09 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace_alt(char c)
{
	if (c == ' ' || c == '\f')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int ft_is_bad_row(char *str)
{
    int i;

    i = 0;
    while (str[i] && ft_isspace(str[i]) == 1)
        i++;
    if (!str[i])
        return (1);
    return (0);
}

void    ft_skip_space(char *str)
{
    int i;
    int len;

    /*  1st part - remove beginning */
    i = 0;
    while (str[i] && ft_isspace_alt(str[i]) == 1)
        i++;
    len = ft_strlcpy(str, str + i, ft_strlen(str));
    i = 0;
    while (str[len + i])
    {
        str[len + i] = '\0';
        i++;
    }
}

void    ft_modify_row(char *str)
{
    int i;
    int j;

    // str = "            f             123/345/654            "
    ft_skip_space(str);
    // str = "f             123/345/654            "

    i = 0;
    while (ft_isspace_alt(str[i]) == 0)
        i++;
    i++;
    // str + i = "            123/345/654            "
    ft_skip_space(str + i);
    // str + i = "123/345/654            "
    // str = "f 123/345/654            "
    j = 0;
    while (ft_isspace_alt((str + i)[j]) == 0)
        j++;
    // str + i + j = "            \n"
    ft_skip_space(str + i + j);
}


