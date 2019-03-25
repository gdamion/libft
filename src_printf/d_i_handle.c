/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_i_handle.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:01:55 by gdamion-          #+#    #+#             */
/*   Updated: 2019/03/25 10:57:59 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static long long	g_di;
static char			*g_num;
static int			g_pre;
static int			g_numlen;
static int			g_zeronum;
static int			g_i;

int					add_pre(void)
{
	if (g_a.flags[2] == '+' && g_di >= 0)
	{
		PRINT('+');
		return (1);
	}
	else if (g_a.flags[1] == ' ' && g_di >= 0)
	{
		PRINT(' ');
		return (1);
	}
	else if (g_di < 0)
	{
		PRINT('-');
		return (1);
	}
	return (0);
}

static void			d_i_recieve(void)
{
	if (!(ft_strcmp(g_a.length, "l")))
		g_di = va_arg(g_ap, long);
	else if (!(ft_strcmp(g_a.length, "ll")))
		g_di = va_arg(g_ap, long long);
	else if (!(ft_strcmp(g_a.length, "h")))
		g_di = (short)va_arg(g_ap, int);
	else if (!(ft_strcmp(g_a.length, "hh")))
		g_di = (char)va_arg(g_ap, int);
	else
		g_di = va_arg(g_ap, int);
	if (g_di < 0)
		g_num = ft_abs_itoa_long(-g_di);
	else
		g_num = ft_abs_itoa_long(g_di);
	g_numlen = ft_strlen(g_num);
}

static void			d_i_minflag(void)
{
	g_pre = add_pre();
	g_zeronum = g_a.prec - g_numlen;
	g_i = g_zeronum;
	if (g_zeronum < 0)
		g_zeronum = 0;
	while (g_i > 0)
	{
		PRINT('0');
		g_i--;
	}
	if (!(g_a.prec == 0 && g_di == 0))
	{
		ft_putstr(g_num);
		g_printed += g_numlen;
	}
	else
	{
		PRINT(' ');
	}
	g_i = g_a.width - (g_pre + g_zeronum + g_numlen);
	while (g_i > 0)
	{
		PRINT(' ');
		g_i--;
	}
}

static void			d_i_noflag(void)
{
	g_i = g_a.width - (g_zeronum + g_numlen);
	while (g_i > 1)
	{
		PRINT(' ');
		g_i--;
	}
	if (!add_pre() && g_i == 1)
	{
		PRINT(' ');
	}
	while (g_zeronum > 0)
	{
		PRINT('0');
		g_zeronum--;
	}
	if (!(g_a.prec == 0 && g_di == 0))
	{
		ft_putstr(g_num);
		g_printed += g_numlen;
	}
	else if (g_a.prec == 0 && g_di == 0 && g_a.width > 0)
	{
		PRINT(' ');
	}
}

void				d_i_process(void)
{
	d_i_recieve();
	if (g_a.flags[3] == '-')
		d_i_minflag();
	else if (g_a.flags[0] == '0' && g_a.prec == -1)
	{
		g_i = g_a.width - (add_pre() + g_numlen);
		while (g_i > 0)
		{
			PRINT('0');
			g_i--;
		}
		g_printed += g_numlen;
		ft_putstr(g_num);
	}
	else
	{
		g_zeronum = g_a.prec - g_numlen;
		if (g_zeronum < 0)
			g_zeronum = 0;
		d_i_noflag();
	}
	free(g_num);
}
