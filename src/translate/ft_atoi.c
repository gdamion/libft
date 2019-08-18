/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 12:35:28 by gdamion-          #+#    #+#             */
/*   Updated: 2019/08/18 14:37:44 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_findnum(unsigned long *res, const char *str, int min)
{
	size_t i;

	i = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		*res = *res * 10 + (int)str[i] - 48;
		if (*res > 9223372036854775807)
		{
			if (min == -1)
				return (0);
			else
				return (-1);
		}
		i++;
	}
	return (1);
}

int			ft_atoi(const char *str)
{
	unsigned long	res;
	int				min;
	size_t			i;
	int				ovflow;

	res = 0;
	min = 1;
	i = 0;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
		(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		min = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	ovflow = ft_findnum(&res, &(str[i]), min);
	if (ovflow != 1)
		return (ovflow);
	return ((int)(min * res));
}
