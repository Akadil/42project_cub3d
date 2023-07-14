/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:45:52 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/14 15:56:23 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct_list.h"
#include "struct_data.h"
#include "libft.h"

/**
 * @brief       parse and check the textures
 * 
 * @return (int)    the exit code. Save the results in (t_data *)data
 */
int ft_parsing_textures(t_list *rows, t_data *data)
{
    if (ft_check_direction_names(rows, data) != 0)
        return (-1);
    if (ft_check_file_existence_wall(data) != 0)
        return (-1);
    return (0);
}

/**
 * @brief   try to open them and check if they exist
 * 
 * @return  (int)   result depending on file existence
 */
int ft_check_file_existence_wall(t_data *data)
{
	int		fd;

	fd = open(data->wall.north.name + 3, O_RDONLY);
	if (fd == -1)
        return (-1);
   	close(fd); 
    fd = open(data->wall.south, O_RDONLY);
	if (fd == -1)
        return (-1);
   	close(fd); 
    fd = open(data->wall.west, O_RDONLY);
	if (fd == -1)
        return (-1);
   	close(fd); 
    fd = open(data->wall.east, O_RDONLY);
	if (fd == -1)
        return (-1);
   	close(fd); 
	if(check_valid_rgb(data->wall.floor.name + 2) == 1)
        return (-1);
    data->wall.floor.color = set_rgb_colors(data->wall.floor.name + 2);
    if(check_valid_rgb(data->wall.ceil) == 1)
        return (-1);
    data->wall.ceil.color = set_rgb_colors(data->wall.ceil.name + 2);
    return (0);
}

int ft_is_wall(t_data *data, char *content)
{
    if (ft_strncmp(content, "NO ", 3) == 0 && !data->wall.north.name)
        return (1);
    else if (ft_strncmp(content, "SO ", 3) == 0 && !data->wall.souht.name)
        return (1);
    else if (ft_strncmp(content, "WE ", 3) == 0 && !data->wall.west.name)
        return (1);
    else if (ft_strncmp(content, "EA ", 3) == 0 && !data->wall.east.name)
        return (1);
    return (0);
}

int ft_is_ceil_floor(t_data *data, char *content)
{
    if (!ft_strncmp((char *)head->content, "C ", 2))
        if (!data->wall.ceil.name)
            return (1);
    else if (!ft_strncmp((char *)head->content, "F ", 2))
        if (!data->wall.floor.name)
            return (1);
    return (0);
}

void    ft_assign_names_wall(t_data *data, t_list *row)
{
    if (ft_strncmp((char *)row->content, "NO ", 3) == 0)
    {
        data->wall.north.name = (char *)row->content + 3;
        data->wall.north.name[ft_strlen(data->wall.north.name) - 1] = '\0';
    }
    else if (ft_strncmp((char *)row->content, "SO ", 3) == 0)
    {
        data->wall.south.name = (char *)row->content + 3;
        data->wall.south.name[ft_strlen(data->wall.south.name) - 1] = '\0';
    }
    else if (ft_strncmp((char *)row->content, "WE ", 3) == 0)
    {
        data->wall.west.name = (char *)row->content + 3;
        data->wall.west.name[ft_strlen(data->wall.west.name) - 1] = '\0';
    }
    else if (ft_strncmp((char *)row->content, "EA ", 3) == 0)
    {
        data->wall.east.name = (char *)row->content + 3;
        data->wall.east.name[ft_strlen(data->wall.east.name) - 1] = '\0';
    }
}

void    ft_assign_names_floor_ceil(t_data *data, t_list *row)
{
    if (ft_strncmp((char *)row->content, "C ", 2) == 0)
    {
        data->wall.ceil.name = (char *)row->content + 2;
        data->wall.ceil.name[ft_strlen(data->wall.ceil.name) - 1] == '\0';
    }
    else if (ft_strncmp((char *)row->content, "F ", 2) == 0)
    {
        data->wall.floor.name = (char *)row->content + 2;
        data->wall.floor.name[ft_strlen(data->wall.floor.name) - 1] == '\0';
    }
}

void    ft_check_direction_names(t_list *head, t_data *data)
{
    while (ft_strncmp((char *)head->content, "1", 1) != 0)
    {
        if (ft_is_wall(data, (char *)head->content) == 1)
            ft_assign_names_wall(data, head);
        else if (ft_is_ceil_floor(data, (char *)head->content) == 1)
            ft_assign_names_floor_ceil(data, (char *)head->content);
        else
            return (ft_error(), -1);
        head = head->next;
    }
    return (0);
}
