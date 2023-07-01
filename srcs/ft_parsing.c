/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:06:51 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/01 14:48:16 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "struct_list.h"

typedef struct s_wall
{
    void    *north;
    void    *south;
    void    *west;
    void    *east;
    void    *floor;
    void    *ceil;
}   t_wall;

void    ft_parsing(int argc, char **argv, t_data *data)
{
    t_list  *rows;
    int     fd;

    fd = ft_parsing_args(argc, argv);
    rows = ft_get_rows(fd);
    ft_parse_textures(rows);

    ft_get_textures();
    ft_parse_textures();
    ft_parse_map();
}

/*  Functions to write  */

/**
 * @brief       Check the arguments and file existence
 * 
 * @details     The name of the file (argv[1]) could be wrongly formatted. Check
 *              for proper name. check if it exists, and return fd (int) value 
 *              if exists 
 * 
 * @return int  -   if everything is ok, return fd of the file
 */
int	ft_parsing_args(int argc, char **argv)
{
	int fd;
    
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

#include "libft.h"

/* Result:  all cleared rows */
void    ft_get_rows(int fd)
{
    t_list  *rows;
    t_list  *row;
    char    *str;

    rows = NULL;
    str = get_next_line(fd);
    while (str)
    {
        if (ft_strcmp(str, "\n") != 0)
        {
            row = ft_lstnew(str);
            if (!row)
                printf("do something");
            ft_lstadd_back(&rows, row);
        }
        else
            free(str);
        str = get_next_line(fd);
    }
    return (rows);
}

/*  */
void    ft_parse_textures(t_list *rows);
{
    t_wall  *wall;
    t_list  *row;
    char    **img_info;

    row = rows;
    while (row)
    {
        img_info = ft_split(row->content);
        
        /*  Two basics tests    */
        if (!img_info)
            printf("Error!");
        if (ft_strlen_alt(img_info) != 2)
            printf("Error!");

        /*  Allocate  */
        if (ft_strcmp(img_info[0], "NO") == 0)
            wall->north = img_info[1];
        else if (ft_strcmp(img_info[0], "SO") == 0)
            wall->south = img_info[1];
        else if (ft_strcmp(img_info[0], "WE") == 0)
            wall->west = img_info[1];
        else if (ft_strcmp(img_info[0], "EA") == 0)
            wall->east = img_info[1];
        else if (ft_strcmp(img_info[0], "F") == 0)
            wall->floor = img_info[1];
        else if (ft_strcmp(img_info[0], "C") == 0)
            wall->ceil = img_info[1];
        else
            printf("Wrong map coordinates!\n");         // Clean if wrong
        row = row->next;
    }
    return (wall);
}
