/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 15:20:04 by gdamion-          #+#    #+#             */
/*   Updated: 2019/04/05 15:54:38 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "libft.h"

# define BUFF_SIZE 10
# define FD_STORE_SIZE 2000

typedef struct		s_files
{
	char			*content;
	int				endl;
}					t_files;

int					get_next_line(const int fd, char **line);

#endif
