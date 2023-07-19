/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gm_get_rows.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akalimol <akalimol@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 19:13:33 by akalimol          #+#    #+#             */
/*   Updated: 2023/03/11 19:15:38 by akalimol         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GM_GET_ROWS_H
# define FT_GM_GET_ROWS_H

# include "ft_data.h"
# include "ft_libft.h"
# include "ft_error.h"

void	ft_close_clear_serror(t_data *_data, t_list *_head, int _fd);
void	ft_close_clear_merror(t_data *_data, t_list *_head, int _fd);

#endif