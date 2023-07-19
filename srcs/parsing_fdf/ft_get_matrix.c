/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 19:35:30 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/11 19:07:53 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_get_matrix.h"

/*
	Goal: Get the data about the map from the file 

	ft_get_rows() - Get the data and store it inside of t_list chain list
	ft_fill_matrix() - Copy the data from t_list to my structure
*/
void	ft_get_matrix(t_data *data, char **argv)
{
	t_list	*rows;
	int		fd;

	fd = my_open(data, argv);
	rows = ft_get_rows(data, fd);
	ft_fill_matrix(data, rows, fd);
	ft_lstclear(&rows, &free);
	close(fd);
}
