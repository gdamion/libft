/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 17:38:37 by gdamion-          #+#    #+#             */
/*   Updated: 2019/08/18 14:37:44 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_cnt(int n)
{
	size_t i;

	i = 0;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	size_t	min;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	min = 0;
	if (n < 0)
	{
		min = 1;
		n = -n;
	}
	len = min + 2 + ft_cnt(n);
	if (!(str = (char*)malloc(len)))
		return (NULL);
	str[--len] = '\0';
	while (len--)
	{
		str[len] = n % 10 + 48;
		n /= 10;
	}
	if (min == 1)
		str[0] = '-';
	return (str);
}
