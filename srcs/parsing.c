/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/01 14:06:51 by akalimol          #+#    #+#             */
/*   Updated: 2023/08/28 18:50:44 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_data.h"
#include <fcntl.h>
#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include "mlx.h"

int		ft_parsing_args(int argc, char **argv, t_list **rows);
t_list	*ft_get_map_rows(t_list **head, t_list **rows_map);
int		ft_parsing_textures(t_list *rows, t_data *data);
int		ft_parsing_map(t_list *rows, t_data *data);

int	check_valid_rgb(char *str);
int	set_rgb_colors(char *str);
int	ft_check_proper_walls(char **map, t_data *data);
int ft_find_largest_height(char **map);

int ft_check_file_existence_wall(t_data *data);
void    ft_check_direction_names(t_list *head, t_data *data);
void	ft_lstclear_alt(t_list **rows_texture, t_list **rows_map);
int	ft_parsing_fdf(t_data *data);
void    ft_free_map(char **map);
t_list	*ft_get_rows_fd(t_fdf *data, int fd);
int	ft_fill_matrix(t_fdf *data, t_list *rows);
void	ft_clean_textures(t_data *data);

/*  Parse and check the inputs, files, maps */
int	ft_parsing(int argc, char **argv, t_data *data)
{
	t_list	*rows_texture;
	t_list	*rows_map;

	rows_texture = NULL;
	rows_map = NULL;
	if (ft_parsing_args(argc, argv, &rows_texture) != 0)
		return (exit(-1), -1);
	if (ft_get_map_rows(&rows_texture, &rows_map) != 0)
		return (ft_lstclear(&rows_texture, &free), exit(-1), -1);
	if (ft_parsing_textures(rows_texture, data) != 0)
		return (ft_clean_textures(data), ft_lstclear_alt(&rows_texture, &rows_map), exit(-1), -1);
	ft_lstclear(&rows_texture, &free);
	if (ft_parsing_map(rows_map, data) != 0)
		return (ft_clean_textures(data), ft_lstclear(&rows_map, &free), exit(-1), -1);
	ft_lstclear(&rows_map, &free);
	ft_parsing_fdf(data);
	return (0);
}

void	ft_clean_textures(t_data *data)
{
	if (data->wall.north.name)
		free (data->wall.north.name);
	if (data->wall.south.name)
		free (data->wall.south.name);
	if (data->wall.west.name)
		free (data->wall.west.name);
	if (data->wall.east.name)
		free (data->wall.east.name);
	if (data->wall.floor.name)
		free (data->wall.floor.name);
	if (data->wall.ceil.name)
		free (data->wall.ceil.name);
}

void	ft_lstclear_alt(t_list **rows_texture, t_list **rows_map)
{
	ft_lstclear(rows_texture, &free);
	ft_lstclear(rows_map, &free);
}

int	ft_parsing_fdf(t_data *data)
{
	t_list	*rows;
	int		fd;

	fd = open("fdf_maps/42.fdf", O_RDONLY);
	if (fd == -1)
		return (ft_putstr_fd("FDF fail", 2), ft_clean_textures(data), ft_free_map(data->map), exit(-1), -1);
	rows = ft_get_rows_fd(&data->fdf, fd);
	if (!rows)
		return (ft_putstr_fd("Malloc fail", 2), ft_clean_textures(data), ft_free_map(data->map), exit(-1), -1);
    close(fd);
	if (ft_fill_matrix(&data->fdf, rows) != 0)
	{
		ft_putstr_fd("Malloc fail", 2);
		ft_free_map(data->map);
		ft_lstclear(&rows, &free);
		ft_clean_textures(data);
		return(exit(-1), -1);
	}
	ft_lstclear(&rows, &free);
    data->fdf.param.theta = 0;
	return (0);
}