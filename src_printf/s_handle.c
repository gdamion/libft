/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:02:13 by gdamion-          #+#    #+#             */
/*   Updated: 2019/03/25 10:59:10 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void	s_minflag(char *s)
{
	int i;
	int a;

	if (g_a.prec == 0)
		return ;
	else if (g_a.prec > 0)
		a = ft_strnlen(s, g_a.prec);
	else
		a = ft_strlen(s);
	ft_putnstr(s, g_a.prec);
	g_printed += a;
	i = g_a.width - a;
	while (i > 0)
	{
		PRINT(' ');
		i--;
	}
}

static void	s_noflag(char *s)
{
	int i;
	int a;

	if (g_a.prec == 0)
		return ;
	else if (g_a.prec > 0)
		a = ft_strnlen(s, g_a.prec);
	else
		a = ft_strlen(s);
	g_printed += a;
	i = g_a.width - a;
	while (i > 0)
	{
		PRINT(' ');
		i--;
	}
	ft_putnstr(s, g_a.prec);
}

void		s_process(void)
{
	char	*s;

	s = va_arg(g_ap, char*);
	if (!s)
	{
		ft_putstr("(null)");
		g_printed += 6;
		return ;
	}
	if (g_a.flags[3] == '-')
		s_minflag(s);
	else
		s_noflag(s);
}
