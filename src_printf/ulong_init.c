/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ulong_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 18:06:24 by gdamion-          #+#    #+#             */
/*   Updated: 2019/03/25 10:59:02 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ulong_init(unsigned long long *a)
{
	if (!(ft_strcmp(g_a.length, "l")))
		*a = va_arg(g_ap, unsigned long);
	else if (!(ft_strcmp(g_a.length, "ll")))
		*a = va_arg(g_ap, unsigned long long);
	else if (!(ft_strcmp(g_a.length, "h")))
		*a = (unsigned short)va_arg(g_ap, unsigned int);
	else if (!(ft_strcmp(g_a.length, "hh")))
		*a = (unsigned char)va_arg(g_ap, unsigned int);
	else
		*a = va_arg(g_ap, unsigned int);
}
