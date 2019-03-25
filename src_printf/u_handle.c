/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:02:18 by gdamion-          #+#    #+#             */
/*   Updated: 2019/03/25 10:59:06 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static unsigned long long	g_u;
static char					*g_num;
static int					g_numlen;
static int					g_zeronum;
static int					g_n;

static void					u_minflag(void)
{
	g_zeronum = g_a.prec - g_numlen;
	if (g_zeronum > 0)
	{
		g_n = g_zeronum;
		while (g_n > 0)
		{
			PRINT('0');
			g_n--;
		}
	}
	else
		g_zeronum = 0;
	if (!(g_a.prec == 0 && g_u == 0))
	{
		ft_putstr(g_num);
		g_printed += g_numlen;
	}
	g_n = g_a.width - (g_zeronum + g_numlen);
	while (g_n > 0)
	{
		PRINT(' ');
		g_n--;
	}
}

static void					u_zeroflag(void)
{
	g_zeronum = g_a.width - g_numlen;
	if (g_zeronum > 0)
		while (g_zeronum > 0)
		{
			PRINT('0');
			g_zeronum--;
		}
	ft_putstr(g_num);
	g_printed += g_numlen;
}

static void					u_noflag(void)
{
	if (g_a.prec > g_numlen)
		g_zeronum = g_a.prec - g_numlen;
	else
		g_zeronum = 0;
	g_n = g_a.width - (g_zeronum + g_numlen);
	while (g_n > 0)
	{
		PRINT(' ');
		g_n--;
	}
	while (g_zeronum > 0)
	{
		PRINT('0');
		g_zeronum--;
	}
	if (!(g_a.prec == 0 && g_u == 0))
	{
		g_printed += g_numlen;
		ft_putstr(g_num);
	}
}

void						u_process(void)
{
	ulong_init(&g_u);
	g_num = ft_abs_itoa_long(g_u);
	g_numlen = ft_strlen(g_num);
	if (g_a.flags[3] == '-')
		u_minflag();
	else if (g_a.flags[0] == '0' && g_a.prec == -1)
		u_zeroflag();
	else
		u_noflag();
	free(g_num);
}
