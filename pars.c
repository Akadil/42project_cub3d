#include "struct_list.h"
#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * @brief       Parse and check the map
 *  
 * @return (int)    the result. 0 if everything is ok, - if wrong 
 */
int ft_parsing_map(t_list *rows)
{
    char    **map;
    int     i;

    if (ft_lstsize(rows) <= 2)
        return (-1);
    if (ft_check_player_existense(rows) != 0)
        return (-1);
    if (ft_check_proper_walls(rows) != 0)
        return (-1);
    map = (char **)malloc(sizeof(char *) * (ft_lstsize(rows) + 1));
    if (!map)
        return (-1);
    
    // /*  Assign the values */
    // ft_assign_values(rows, map);

    // /*  As we already parsed everything, we can free the row lists  */
    // ft_clean_rows(rows);

    // /*  Find player and assign his values to data->player   */
    // ft_find_player(map);
}


//check the arguments and .cub
int	ft_parsing_args(int argc, char **argv, t_list **rows)
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

//check that the map is surrounded by walls, invalid map char, find the unique player
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

int ft_check_map(t_data *data)
{	
    int cols = strlen(rows->content);
    int rows = ft_lstsize(rows);
    int x;
    int y;
    y = 0;
    int player_x;
    int player_y;
    int player_exists = 0;
    while (data->map[y])
    {
        while (data->map[y][x])
        {
            //find the player
            if(data->map[y][x] == 'N' || data->map[y][x] == 'E' ||data->map[y][x] == 'S' || data->map[y][x] == 'W' )
            {
                if(player_exists == 1)
                {
                    ft_printf("Player should be unique.\n");
                    return 0;
                }
                player_x = x;
                player_y = y;
                player_exists++;
            }
            //Check if map has valid characters
            if(!valid_char(data->map[y][x]))
            {
                ft_printf("Error: Invalid map character");
                return 0;
            }
            //check walls
            if(data->map[0][x] != WALL || data ->map[rows-1][x] != WALL || data->map[y][0] != WALL || data->map[y][cols-1] != WALL)
            {
                ft_printf("Error: Map should be surrounded with walls");
                return 0;
            }
            x++;
        }
        y++;
    }
    return 1;
}