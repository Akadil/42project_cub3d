/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aseisenb <aseisenb@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 17:17:25 by aseisenb          #+#    #+#             */
/*   Updated: 2023/08/29 17:08:13 by aseisenb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_parsing_args.h"

/**
 * @brief   Parse and check arguments
 *
 * @param rows  linked list to store the data
 * @return int  0 in success
 */
int	ft_parsing_args(int argc, char **argv, t_list **rows)
{
	t_list	*head;
	int		fd;

	if (ft_check_args(argc, argv) != 0)
		return (-1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (perror(argv[1]), -1);
	head = ft_get_rows(fd);
	if (!head)
		return (perror(NULL), -1);
	close(fd);
	*rows = head;
	return (0);
}

int	ft_check_args(int argc, char **argv)
{
	if (argc == 1)
	{
		ft_printf2("No args.\n");
		return (-1);
	}
	if (argc > 2)
		ft_printf2("Only the first file would be used.\n");
	if (ft_strlen(argv[1]) < 4)
		return (ft_printf2("Map should be a .cub file.\n"), -1);
	if (ft_strcmp(argv[1] + ft_strlen(argv[1]) - 4, ".cub") != 0)
	{
		ft_printf2("Map should be a .cub file.\n");
		return (-1);
	}
	return (0);
}

/*  Protected   */
t_list	*ft_get_rows(int fd)
{
	t_list	*rows;
	t_list	*row;
	char	*str;

	rows = NULL;
	str = get_next_line(fd, 0);
	while (str)
	{
		if (ft_is_bad_row(str) != 0)
			free(str);
		else
		{
			if (!ft_strncmp(str, "NO", 2) || !ft_strncmp(str, "SO", 2)
				|| !ft_strncmp(str, "EA", 2) || !ft_strncmp(str, "WE", 2))
				ft_modify_row(str);
			else if (*str != '0' && *str != '1')
				ft_modify_row(str);
			row = ft_lstnew(str, 0);
			if (!row)
				return (ft_lstclear(&rows, &free), NULL);
			ft_lstadd_back(&rows, row);
		}
		str = get_next_line(fd, 0);
	}
	return (rows);
}
