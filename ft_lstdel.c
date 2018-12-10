/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <gdamion-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:30:55 by gdamion-          #+#    #+#             */
/*   Updated: 2018/12/10 19:04:13 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*main;
	t_list	*next;

	if (!alst || !del || !(*alst))
		return ;
	main = *alst;
	while (main != NULL)
	{
		next = main->next;
		del(main->content, main->content_size);
		free(main);
		main = next;
	}
	*alst = NULL;
}
