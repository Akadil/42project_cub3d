#include "libft.h"

typedef enum s_tiletype
{
    EMPTY = '0',
    WALL = '1',
    N = 'N',
    S = 'S',
    E = 'E',
    W = 'W';
} t_tiletype;

int valid_char(char c)
{
    if (c == WALL || c == EMPTY || c == N || c == S || c == E || c == W)
        return (1);
    return (0);
}

int ft_find_largest_height(char **map)
{
    int x;

    while(map[x])
        x++;
    return (x);
}

int	ft_check_proper_walls(char **map)
{
    int x;
	int y;
    int largest_height;

	x = 0;
    largest_height = ft_find_largest_height(data->map);
	while (data->map[x])
	{
		y = 0;
        while (data->map[x][y])
		{
			if (!valid_char(data->map[x][y]))
			{
				ft_printf("Error: Invalid map character");
				return (0);
			}
			if (data->map[x][y] == '0')
            {
                if(x == 0 || y == 0 || x == largest_height - 1 || !map[x][j + 1])
                    return (1);
                else if(data->map[x][y + 1] == ' ' || data ->map[x][y - 1] == ' ' || data->map[x + 1][y] == ' ' || data->map[x - 1][y] != ' ')
                    return (1);
                else if(data->map[x][y + 1] == ' ' || data ->map[x][y - 1] == ' ' || data->map[x + 1][y] == ' ' || data->map[x - 1][y] != ' ')
				    ft_printf("Error: Map should be surrounded with walls");
				return (1);
			}
			y++;
		}
		x++;
	}
    return (0);
}