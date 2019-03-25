/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:38:18 by gdamion-          #+#    #+#             */
/*   Updated: 2019/03/25 10:52:15 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*in;
	unsigned char	*out;

	i = 0;
	in = (unsigned char*)src;
	out = dest;
	while (i < n)
	{
		out[i] = in[i];
		i++;
	}
	return (dest);
}
