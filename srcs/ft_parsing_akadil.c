/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_akadil.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:40:25 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/07 12:40:00 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "struct_list.h"
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

void    ft_parsing_akadil(int argc, char **argv, t_data *data)
{
    t_list  *head;
    t_list  *row;
    int      fd;
    char        *str;

    (void)data;
    (void)argc;
    
    /* ======================================================== */
                        /*  Parse the map   */
    /* ======================================================== */
    head = NULL;
    fd = open(argv[1], O_RDONLY);
    str = get_next_line(fd, 0);
    while (str)
    {
        row = ft_lstnew(str, 0);
        ft_lstadd_back(&head, row);
        str = get_next_line(fd, 0);
    }
    get_next_line(0, 1);
    close (fd);


    /* ======================================================== */
                        /*  Get the texture */
    /* ======================================================== */

    // Ignore the texture for now
    while (ft_strncmp((char *)head->content, "1", 1) != 0)
        head = head->next;


    /* ======================================================== */
                        /*  get the map */
    /* ======================================================== */

    char    **map;
    int     i;

    map = (char **)malloc(sizeof(char *) * (ft_lstsize(head) + 1));
    i = 0;
    row = head;
    while (row)
    {
        map[i] = (char *)row->content;
        row = row->next;
        i++;
    }
    map[i] = NULL;
    data->map = map;


    /* ======================================================== */
                        /*  Find the player */
    /* ======================================================== */
    int j;
    int checker;

    i = 0;
    checker = 0;
    while (map[i] && checker == 0)
    {
        j = 0;
        while (map[i][j] && checker == 0)
        {
            if (map[i][j] != '1' && map[i][j] != '0' && map[i][j] != ' ' && map[i][j] != '\n')
            {
                data->player.x = j + 0.5;
                data->player.y = i + 0.5;
                data->angle = 300.0;
                checker = 1;
            }
            j++;
        }
        i++;
    }


    /* ======================================================== */
                        /*  Start the mlx   */
    /* ======================================================== */
    
    data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	data->img_win.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img_win.addr = mlx_get_data_addr(data->img_win.mlx_img, &data->img_win.bpp, \
									&data->img_win.line_len, &data->img_win.endian);;
    
}


/* ======================================================== */
                /*  test parts of function  */
/* ======================================================== */

t_list    *ft_parsing_akadil_test_parsing(int argc, char **argv, t_data *data)
{
    t_list  *head;
    t_list  *row;
    int      fd;
    char        *str;

    (void)data;
    (void)argc;
    head = NULL;
    fd = open(argv[1], O_RDONLY);
    str = get_next_line(fd, 0);
    while (str)
    {
        row = ft_lstnew(str, 0);
        ft_lstadd_back(&head, row);
        str = get_next_line(fd, 0);
    }
    get_next_line(0, 1);
    close (fd);
    return (head);
}