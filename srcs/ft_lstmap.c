/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <gdamion-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:50:06 by gdamion-          #+#    #+#             */
/*   Updated: 2018/12/05 17:50:06 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *buf;
	t_list *nbuf;
	t_list *nlst;
	
	if (!lst || !f)
		return (NULL);
	buf = lst;
	nlst = ft_lstnew(0, sizeof(lst));	
	nbuf = nlist;
	while (buf->next != NULL)
	{
		if (f(buf))
		{
		nlst->next =
		}
		buf = buf->next;

	}
	nlst->next = NULL;
	return (nbuf);
	}
	return (NULL);
}