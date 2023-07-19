/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_matrix_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:05:51 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/16 16:13:40 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_data.h"
#include "ft_error.h"
#include <fcntl.h>

int	my_open(t_data *_my_data, char **_argv)
{
	int	fd;

	fd = open(_argv[1], O_RDONLY);
	if (fd == -1)
		ft_perror_clean_exit(_my_data, _argv[1]);
	return (fd);
}
