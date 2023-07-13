/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:41:16 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/13 19:53:53 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_parsing_args.h"

int ft_parsing_args(int argc, char **argv, t_list **rows)
{
    t_list  *head;
    int     fd;

    /*  Check the arguments */
    if (ft_check_args(argc, argv) != 0)
        return (-1);

    /*  Open the file   */
    fd = open(argv[1], O_RDONLY);
    if (fd == -1)
        return (-1);

    /* the code ... */
    head = ft_get_rows(fd);

    *rows = head;
    return (0);
}

int	ft_check_args(int argc, char **argv)
{
	int fd;
    int i;
    
    i = 0;
    if (argc == 1)
	{
		ft_printf("No args.\n");
		return (-1);
	}
	if (argc > 2)
		ft_printf("Only the first file would be used.\n");
	if (!(argv[1][i - 4] == '.' && argv[1][i - 3] == 'c'\
		&& argv[1][i - 2] == 'u' && argv[1][i - 1] == 'b'))
	{
		ft_printf("Map should be a .cub file.\n");
		return (-1);
	}
    return (0);
}

void    ft_get_rows(int fd)
{
    t_list  *rows;
    t_list  *row;
    char    *str;

    rows = NULL;
    str = get_next_line(fd, 0);
    while (str)
    {
        if (ft_is_bad_row(str) == 1)
            free (line);
        else
        {
            ft_modify_row(str);
            row = ft_lstnew(str, 0);
            if (!row)
                printf("do something");
            ft_lstadd_back(&rows, row);
        }
        str = get_next_line(fd, 0);
    }
    return (rows);
}
