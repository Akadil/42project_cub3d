/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_akadil.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:40:25 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/14 16:05:51 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include "struct_list.h"
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"
#include <math.h>

void    ft_parsing_akadil(int argc, char **argv, t_data *data)
{
    t_list  *head;
    t_list  *row;
    int      fd;
    char        *str;

    (void)argc;
    
    /* ======================================================== */
                        /*  Parse the map   */
    /* ======================================================== */

    int largest_row = -1;

    head = NULL;
    fd = open(argv[1], O_RDONLY);
    str = get_next_line(fd, 0);
    while (str)
    {
        if ((int)ft_strlen(str) > largest_row)
            largest_row = ft_strlen(str);
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
    {
        if (ft_strncmp((char *)head->content, "NO", 2) == 0)
        {
            data->wall.north.addr = (char *)head->content + 3;                      // Remove the beginning
            data->wall.north.addr[ft_strlen(data->wall.north.addr) - 1] = '\0';     // Remove the newline at the end
        }
        else if (ft_strncmp((char *)head->content, "SO", 2) == 0)
        {
            data->wall.south.addr = (char *)head->content + 3;
            data->wall.south.addr[ft_strlen(data->wall.south.addr) - 1] = '\0';
        }
        else if (ft_strncmp((char *)head->content, "WE", 2) == 0)
        {
            data->wall.west.addr = (char *)head->content + 3;
            data->wall.west.addr[ft_strlen(data->wall.west.addr) - 1] = '\0';
        }
        else if (ft_strncmp((char *)head->content, "EA", 2) == 0)
        {
            data->wall.east.addr = (char *)head->content + 3;
            data->wall.east.addr[ft_strlen(data->wall.east.addr) - 1] = '\0';
        }
        head = head->next;
    }



    // int     size;

    // row = head;
    // while (row)
    // {
    //     if ((int)ft_strlen((char *)row->content) < largest_row)
    //     {
    //         str = (char *)ft_calloc(sizeof(char), largest_row + 1);
    //         size = (int)ft_strlcpy(str, (char *)row->content, largest_row + 1);
    //         while (size < largest_row)
    //         {
    //             str[size] = '8';
    //             size++;
    //         }
    //         free (row->content);
    //         row->content = str;
    //     }
    //     row = row->next;
    // }


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
                data->angle = 270.0;
                checker = 1;
            }
            j++;
        }
        i++;
    }

    data->view.dir.x = cos(data->angle * PI / 180);
    data->view.dir.y = sin(data->angle * PI / 180);
    data->view.plane.x = 0.66 * sin (data->angle * PI / 180) * -1;
    data->view.plane.y = 0.66 * cos (data->angle * PI / 180);

    /* ======================================================== */
                        /*  Start the mlx   */
    /* ======================================================== */
    
    data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "cub3d");
	data->img_win.mlx_img = mlx_new_image(data->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data->img_win.addr = mlx_get_data_addr(data->img_win.mlx_img, &data->img_win.bpp, &data->img_win.line_len, &data->img_win.endian);
    data->img_minimap.mlx_img = mlx_new_image(data->mlx_ptr, (int)(WINDOW_WIDTH / 4), (int)(WINDOW_HEIGHT / 4));
	data->img_minimap.addr = mlx_get_data_addr(data->img_minimap.mlx_img, &data->img_minimap.bpp, &data->img_minimap.line_len, &data->img_minimap.endian);

    /* ======================================================== */
                        /*  Parsing the images  */
    /* ======================================================== */
    data->wall.north.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->wall.north.addr, &data->wall.north.width, &data->wall.north.height);
    data->wall.south.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->wall.south.addr, &data->wall.south.width, &data->wall.south.height);
    data->wall.west.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->wall.west.addr, &data->wall.west.width, &data->wall.west.height);
    data->wall.east.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->wall.east.addr, &data->wall.east.width, &data->wall.east.height);

    data->wall.north.addr = mlx_get_data_addr(data->wall.north.mlx_img, &data->wall.north.bpp, &data->wall.north.line_len, &data->wall.north.endian);
    data->wall.south.addr = mlx_get_data_addr(data->wall.south.mlx_img, &data->wall.south.bpp, &data->wall.south.line_len, &data->wall.south.endian);
    data->wall.west.addr = mlx_get_data_addr(data->wall.west.mlx_img, &data->wall.west.bpp, &data->wall.west.line_len, &data->wall.west.endian);
    data->wall.east.addr = mlx_get_data_addr(data->wall.east.mlx_img, &data->wall.east.bpp, &data->wall.east.line_len, &data->wall.east.endian);

    data->event.rotation_speed = 3;
    // int x, y;
    // for (y = 0; y < data->wall.north.height; y++) {
    //     for (x = 0; x < data->wall.north.width; x++) {
    //         // Calculate pixel position in image_data array
    //         int pos = (y * data->wall.north.line_len) + (x * (data->wall.north.bpp / 8));

    //         // Access individual color channels of the pixel
    //         int red = data->wall.north.addr[pos];
    //         int green = data->wall.north.addr[pos + 1];
    //         int blue = data->wall.north.addr[pos + 2];

    //         // Manipulate pixel values as needed
    //         // ...

    //         // Example: Print pixel RGB values
    //         printf("Pixel at (%d, %d): R=%d, G=%d, B=%d\n", x, y, red, green, blue);
    //     }
    // }
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