/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <gdamion-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 15:43:19 by gdamion-          #+#    #+#             */
/*   Updated: 2018/12/05 15:43:19 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *newel;

	if (newel = (t_list*)malloc(sizeof(t_list)))
	{
		newel->content = content;
		newel->content_size = content_size;
		newel->next = NULL;
		return (newel);
	}
	return (NULL);
}
