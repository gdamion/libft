/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:30:55 by gdamion-          #+#    #+#             */
/*   Updated: 2019/03/25 10:49:48 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*head;
	t_list	*next;

	if (!alst || !del || !(*alst))
		return ;
	head = *alst;
	while (head != NULL)
	{
		next = head->next;
		del(head->content, head->content_size);
		free(head);
		head = next;
	}
	*alst = NULL;
}
