/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_akadil.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:40:25 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/04 15:34:23 by akalimol         ###   ########.fr       */
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

void	ft_fill_matrix(t_fdf *data, t_list *rows);
t_list	*ft_get_rows(t_fdf *data, int fd);

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
                data->sprite_pos.x = j + 0.5;
                data->sprite_pos.y = i + 0.5;
                data->angle = 0.0;
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

    data->sprite.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, "pics/barrel.xpm", &data->sprite.width, &data->sprite.height);
    data->sprite.addr = mlx_get_data_addr(data->sprite.mlx_img, &data->sprite.bpp, &data->sprite.line_len, &data->sprite.endian);

    data->event.rotation_speed = 3;
    data->event.move_fw = false;
    data->event.move_bw = false;
    data->rays = (double *)ft_calloc(sizeof(double), WINDOW_WIDTH);

    t_list  *rows;

	fd = open("fdf_maps/42.fdf", O_RDONLY);
	rows = ft_get_rows(&data->fdf, fd);
    close(fd);
	ft_fill_matrix(&data->fdf, rows);
	ft_lstclear(&rows, &free);

    data->fdf.param.theta = 0;



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

t_list	*ft_get_rows(t_fdf *data, int fd)
{
	t_list	*head;
	t_list	*temp;
	char	*str;

	head = NULL;
	str = get_next_line(fd, 0);
	while (str)
	{
		temp = ft_lstnew(str, 0);
		if (!temp)
			printf("Error!\n");
		ft_lstadd_back(&head, temp);
		str = get_next_line(fd, 0);
	}
	get_next_line(fd, 1);
	if (!head)
		printf("Error!\n");
	data->mtrx.height = ft_lstsize(head);
	return (head);
}

void	ft_find_width(t_fdf *data, t_list *rows)
{
	char	*line;
	int		width;
	int		i;
	int		prev;

	i = 0;
	width = 0;
	prev = 1;
	line = rows->content;
	while (line[i])
	{
		if (line[i] == ' ' && prev == 0)
		{
			width++;
			prev = 1;
		}
		else if (line[i] != ' ')
			prev = 0;
		i++;
	}
	width++;
	data->mtrx.width = width;
}

void	ft_free_d_array_char(char **trash)
{
	int	i;

	i = 0;
	while (trash[i])
	{
		free(trash[i]);
		i++;
	}
	free(trash);
}

void	ft_set_z_maximas(t_fdf *data, int i, int j)
{
	if (data->mtrx.node[i][j].z > data->mtrx.z_max)
		data->mtrx.z_max = data->mtrx.node[i][j].z;
	if (data->mtrx.node[i][j].z < data->mtrx.z_min)
		data->mtrx.z_min = data->mtrx.node[i][j].z;
}


int	hex_to_dec(char *hex_string)
{
	int		decimal_value;
	int		i;
	int		digit_value;
	char	c;

	decimal_value = 0;
	i = 0;
	while (hex_string[i] != '\0')
	{
		c = hex_string[i];
		if (c >= '0' && c <= '9')
			digit_value = c - '0';
		else if (c >= 'A' && c <= 'F')
			digit_value = c - 'A' + 10;
		else if (c >= 'a' && c <= 'f')
			digit_value = c - 'a' + 10;
		decimal_value = decimal_value * 16 + digit_value;
		i++;
	}
	return (decimal_value);
}

void	ft_init_matrix(t_fdf *data, t_list *rows);

void	ft_fill_matrix(t_fdf *data, t_list *rows)
{
	char	**line;
	int		i;
	int		j;

	ft_init_matrix(data, rows);
	i = -1;
	while (rows && ++i >= 0)
	{
		line = ft_split(rows->content, ' ');
		if (!line)
			printf("Error!\n");
		j = -1;
		while (++j < data->mtrx.width)
		{
			data->mtrx.node[i][j].z = ft_atoi(line[j]);
			ft_set_z_maximas(data, i, j);
			if (ft_strchr(line[j], ','))
				data->mtrx.node[i][j].color = hex_to_dec(ft_strchr(line[j], ',') + 1);
			else
				data->mtrx.node[i][j].color = -1;
		}
		ft_free_d_array_char(line);
		rows = rows->next;
	}
}

void	ft_init_matrix(t_fdf *data, t_list *rows)
{
	t_node	**node;
	int		i;
	int		j;

	ft_find_width(data, rows);
	node = (t_node **)malloc(sizeof(t_node *) * data->mtrx.height);
	if (!node)
        printf("Error!\n");
	i = -1;
	while (++i < data->mtrx.height)
	{
		node[i] = (t_node *)malloc(sizeof(t_node) * data->mtrx.width);
		if (!node[i])
			printf("Error!\n");
		j = 0;
		while (j < data->mtrx.width)
		{
			node[i][j].x = i - (float)(data->mtrx.height - 1) / 2;
			node[i][j].y = j - (float)(data->mtrx.width - 1) / 2;
			j++;
		}
	}
	data->mtrx.node = node;
	data->mtrx.z_max = -2147483648;
	data->mtrx.z_min = 2147483647;
}

