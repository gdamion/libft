/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 17:50:06 by gdamion-          #+#    #+#             */
/*   Updated: 2019/03/25 10:52:49 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *start;
	t_list *add;

	if (!lst || !f)
		return (NULL);
	if (!(add = f(lst)))
		return (NULL);
	start = add;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if (!(add->next = f(lst)))
		{
			free(add->next);
			return (NULL);
		}
		add = add->next;
	}
	return (start);
}
