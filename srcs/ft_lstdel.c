/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <gdamion-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:30:55 by gdamion-          #+#    #+#             */
/*   Updated: 2018/12/05 16:30:55 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
while ((*alstr)->next != NULL)
	{
		del((*alstr)->content, (*alstr)->content_size);
		free(*alstr);
		*alstr = (*alstr)->next;
	}
*alstr = NULL;
}
