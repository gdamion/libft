/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:10:58 by gdamion-          #+#    #+#             */
/*   Updated: 2019/08/18 14:37:44 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t i;
	size_t j;
	size_t k;

	i = 0;
	if (n[i] == '\0')
		return ((char*)h);
	while (h[i] != '\0' && i < len)
	{
		k = i;
		j = 0;
		while (n[j] != '\0' && h[k] != '\0' && h[k] == n[j] && k < len)
		{
			j++;
			k++;
		}
		if (n[j] == '\0')
			return (&(((char*)h)[i]));
		i++;
	}
	return (NULL);
}
