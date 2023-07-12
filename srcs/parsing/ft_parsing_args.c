/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_args.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:41:16 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/12 16:35:27 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "libft.h"

/**
 * @brief       Check the arguments and get the rows
 * 
 * @details     The name of the file (argv[1]) could be wrongly formatted. Check
 *              for proper name. check if it exists, and get the rows as a list 
 * 
 * @todo        1. Check the arguments
 *              2. Open the file
 *              3. Get the rows
 *              4. Check the rows
 *              5. Remove the bad rows
 * 
 * @return int  -   if everything is ok, return fd of the file
 */
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

    *rows = head;
    return (0);
}

/*  Previously written code */
int	ft_parsing_args_previous(int argc, char **argv, t_list **rows)
{
	int fd;
    int i;
    
    i = 0;
    if (argc == 1)
	{
		ft_printf("No args.\n");
		exit (-1);
	}
	if (argc > 2)
		ft_printf("Only the first file would be used.\n");
	if (!(argv[1][i - 4] == '.' && argv[1][i - 3] == 'c'\
		&& argv[1][i - 2] == 'u' && argv[1][i - 1] == 'b'))
	{
		ft_printf("Map should be a .cub file.\n");
		exit (-1);
	}
    fd = open(argv[1], O_RDONLY);
	if (fd < -1)
		ft_printf("Can't open the file.\n");
    return (fd);
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
        if (ft_strcmp(str, "\n") != 0)
        {
            row = ft_lstnew(str, 0);
            if (!row)
                printf("do something");
            ft_lstadd_back(&rows, row);
        }
        else
            free(str);
        str = get_next_line(fd, 0);
    }
    return (rows);
}
