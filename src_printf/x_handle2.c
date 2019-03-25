/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_handle2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:07:43 by gdamion-          #+#    #+#             */
/*   Updated: 2019/03/25 10:58:35 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	g_pre;
static int	g_zeronum;
static int	g_n;

static void	x_minflag2(unsigned long long x, int var, int numlen, char *num)
{
	if (!(g_a.prec == 0 && x == 0))
	{
		ft_putstr(num);
		g_printed += numlen;
	}
	else
	{
		PRINT(' ');
	}
	g_n = g_a.width - (g_pre + g_zeronum + numlen);
	while (g_n > 0)
	{
		PRINT(' ');
		g_n--;
	}
	free(num);
}

void		x_minflag(unsigned long long x, int var, int numlen, char *num)
{
	if (g_a.flags[4] == '#' && x != 0)
	{
		var ? ft_putstr("0X") : ft_putstr("0x");
		g_printed += 2;
		g_pre = 2;
	}
	else
		g_pre = 0;
	g_zeronum = g_a.prec - numlen;
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
	x_minflag2(x, var, numlen, num);
}

void		x_zeroflag(unsigned long long x, int var, int numlen, char *num)
{
	if (g_a.flags[4] == '#' && x != 0)
	{
		var ? ft_putstr("0X") : ft_putstr("0x");
		g_printed += 2;
		g_pre = 2;
	}
	else
		g_pre = 0;
	g_zeronum = g_a.width - (g_pre + numlen);
	if (g_zeronum > 0)
		while (g_zeronum > 0)
		{
			PRINT('0');
			g_zeronum--;
		}
	ft_putstr(num);
	g_printed += numlen;
	free(num);
}

static void	x_noflag2(unsigned long long x, int var, int numlen, char *num)
{
	if (g_pre && x == 0)
	{
		g_printed += 2;
		ft_putstr("  ");
	}
	else if (g_pre)
	{
		var ? ft_putstr("0X") : ft_putstr("0x");
		g_printed += 2;
	}
	while (g_zeronum > 0)
	{
		PRINT('0');
		g_zeronum--;
	}
	if (!(g_a.prec == 0 && x == 0))
	{
		g_printed += numlen;
		ft_putstr(num);
	}
	else
	{
		PRINT(' ');
	}
	free(num);
}

void		x_noflag(unsigned long long x, int var, int numlen, char *num)
{
	if (g_a.flags[4] == '#' && x != 0)
		g_pre = 2;
	else
		g_pre = 0;
	if (g_a.prec > numlen)
		g_zeronum = g_a.prec - numlen;
	else
		g_zeronum = 0;
	g_n = g_a.width - (g_pre + g_zeronum + numlen);
	while (g_n > 0)
	{
		PRINT(' ');
		g_n--;
	}
	x_noflag2(x, var, numlen, num);
}
