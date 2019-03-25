/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   x_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:02:22 by gdamion-          #+#    #+#             */
/*   Updated: 2019/03/25 10:58:58 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static char					*g_num;
static int					g_numlen;

static int	ft_cnt_hex(unsigned long long x)
{
	int i;

	i = 1;
	while (x /= 16)
		i++;
	return (i);
}

static void	in_hexagonal(unsigned long long x, int var)
{
	char	reg;
	int		i;

	ALLOC(g_num, char*, sizeof(char) * (g_numlen + 1));
	g_num[g_numlen] = '\0';
	if (!var)
		reg = 'a';
	else
		reg = 'A';
	i = g_numlen - 1;
	while (x / 16)
	{
		if ((x % 16) < 10)
			g_num[i] = x % 16 + '0';
		else
			g_num[i] = x % 16 - 10 + reg;
		x /= 16;
		i--;
	}
	if ((x % 16) < 10)
		g_num[i] = x % 16 + '0';
	else
		g_num[i] = x % 16 - 10 + reg;
}

void		x_process(int var)
{
	unsigned long long x;

	ulong_init(&x);
	g_numlen = ft_cnt_hex(x);
	in_hexagonal(x, var);
	if (!x && !g_a.prec && !g_a.width)
		return ;
	if (g_a.flags[3] == '-')
		x_minflag(x, var, g_numlen, g_num);
	else if (g_a.flags[0] == '0' && g_a.prec == -1)
		x_zeroflag(x, var, g_numlen, g_num);
	else
		x_noflag(x, var, g_numlen, g_num);
}
