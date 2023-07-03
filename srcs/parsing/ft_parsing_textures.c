/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_textures.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 10:45:52 by akalimol          #+#    #+#             */
/*   Updated: 2023/07/03 12:37:23 by akalimol         ###   ########.fr       */
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
    ft_premodify_rows(rows);
    if (ft_check_texture_names(rows) != 0)
        return (0);
    if (ft_check_file_existence(rows) != 0)
        return (0);
    ft_get_filenames_inside_data(rows, data);

    /*  free the data after */
    ft_free_rows(rows);
}

/**
 * @brief       If any of rows contains spaces in the beginning, then remove them 
 * 
 * @param rows 
 */
void    ft_premodify_rows(t_list *rows);


/**
 * @brief       Check if rows contain all textures and properly formatted
 * 
 * @details     In the meantime assign values for each of values
 *              int type ==     0 - default
 *                              1 - North, 2 - South, 3 - West, 4 - East
 *                              5 - floot, 6 - ceil
 * 
 * @return (int)  result, if something is wrong
 */
int     ft_check_texture_names(t_list *rows)
{
    if (ft_lstsize(rows) != 6)
        return (-1);
    
    /*  Go through each of rows and check if everything exist   */
    while (rows)
    {
        /*  Check if everything is here */
        rows = rows->next;
    }
    return (0);
}


/**
 * @brief   try to open them and check if they exist
 * 
 * @return  (int)   result depending on file existence
 */
int ft_check_file_existence(t_list **rows);


/**
 * @brief   save filenames
 *  
 */
void    ft_get_filenames_inside_data(t_list *rows, t_data *data);


/**
 * @brief   as we already parsing everything, we have to free the list rows
 * 
 */
void    ft_free_rows(t_list *rows);




/*  -------------------------------------------------------------- */
/*  -------------------------------------------------------------- */
/*  -------------------------------------------------------------- */

/*  Previously written code */
int ft_parsing_textures_old(t_list *rows)
{
    t_wall  *wall;
    t_list  *row;
    char    **img_info;

    row = rows;
    while (row)
    {
        img_info = ft_split(row->content, ' ');
        
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
