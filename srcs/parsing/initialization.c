#include <fcntl.h>
#include "libft.h"

void    ft_init_player(t_data *data, char p, int row_num, int i)
{
    data->player.x = row_num;
    data->player.y = i;
    if (p == 'N')
        data->angle = 270.0;
    else if (p == 'E')
        data->angle = 0.0;
    else if (p == 'S')
        data->angle = 90.0;
    else
        data->angle = 180.0;
}

void	ft_init_map(t_list *rows, char **map)
{
	int	i;
    int j;
    int largest_width;
    int len;

    largest_width = ft_find_largest_width(rows);
	i = 0;
	while (rows)
	{
        len = ft_strlen((char *)rows->content);
        if (len < largest_width)  // if (26 < 34)
        {
            map[i] = (char *)ft_calloc(sizeof(char), largest_width + 1);
            if (!map[i])
                return (0);     // Fix me!
            j = 0;
            // Do slesh n
            while (((char *)rows->content)[j] && ((char *)rows->content)[j] != '\n')
            {
                map[i][j] = ((char *)rows->content)[j];
                j++;
            }
            while (j < largest_width)
            {
                map[i][j] = ' ';
                j++;
            }
            map[i][j] = '\0';
            free (rows->content);
        }
        else
		    map[i] = (char *)rows->content;
		rows = rows->next;
		i++;
	}
	map[i] = NULL;
}

void    init_images(int argc, char **argv, t_data *data)
{
    data->wall.north.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->wall.north.addr, &data->wall.north.width, &data->wall.north.height);
    if(!data->wall.north.mlx_img)
       return (ft_error(""), -2);
    data->wall.south.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->wall.south.addr, &data->wall.south.width, &data->wall.south.height);
    if(!data->wall.south.mlx_img)
        ft_error();
    data->wall.west.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->wall.west.addr, &data->wall.west.width, &data->wall.west.height);
    if(!data->wall.west.mlx_img)
        ft_error();
    data->wall.east.mlx_img = mlx_xpm_file_to_image(data->mlx_ptr, data->wall.east.addr, &data->wall.east.width, &data->wall.east.height);
    if(!data->wall.east.mlx_img)
        ft_error();
    data->wall.north.addr = mlx_get_data_addr(data->wall.north.mlx_img, &data->wall.north.bpp, &data->wall.north.line_len, &data->wall.north.endian);
    if(!data->wall.north.addr)
        ft_error(-2);
    data->wall.south.addr = mlx_get_data_addr(data->wall.south.mlx_img, &data->wall.south.bpp, &data->wall.south.line_len, &data->wall.south.endian);
    if(!data->wall.south.addr)
        ft_error();
    data->wall.west.addr = mlx_get_data_addr(data->wall.west.mlx_img, &data->wall.west.bpp, &data->wall.west.line_len, &data->wall.west.endian);
    if(!data->wall.south.addr)
        ft_error();
    data->wall.east.addr = mlx_get_data_addr(data->wall.east.mlx_img, &data->wall.east.bpp, &data->wall.east.line_len, &data->wall.east.endian);
    if(!data->wall.south.addr)
        ft_error();
}