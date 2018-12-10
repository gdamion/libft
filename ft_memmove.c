/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <gdamion-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:21:52 by gdamion-          #+#    #+#             */
/*   Updated: 2018/12/10 20:00:58 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*in;
	unsigned char	*out;

	in = (unsigned char*)src;
	out = (unsigned char*)dest;
	if (in < out)
	{
		i = n - 1;
		while ((int)i >= 0)
		{
			out[i] = in[i];
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < n)
		{
			out[i] = in[i];
			i++;
		}
	}
	return (dest);
}
