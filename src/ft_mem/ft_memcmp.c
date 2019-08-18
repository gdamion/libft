/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:17:27 by gdamion-          #+#    #+#             */
/*   Updated: 2019/08/18 14:37:44 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*s1m;
	unsigned char	*s2m;

	i = 0;
	s1m = (unsigned char*)s1;
	s2m = (unsigned char*)s2;
	while (i < n)
	{
		if (s1m[i] != s2m[i])
			return (s1m[i] - s2m[i]);
		i++;
	}
	return (0);
}
