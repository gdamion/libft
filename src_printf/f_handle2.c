/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_handle2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 16:40:15 by gdamion-          #+#    #+#             */
/*   Updated: 2019/03/25 10:58:04 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int		g_i;
static int		g_j;
static int		g_min;
static char		*g_big;
static int		g_dot;
static int		*g_calc_num;
static int		g_op;

static void		add_to_int_arr(long double f)
{
	while (g_i < ALLOC_SIZE)
	{
		f *= 10;
		g_op = (int)f;
		f -= g_op;
		g_calc_num[g_i] = g_op;
		g_i++;
	}
	g_i = ALLOC_SIZE - 1;
	while (g_i > g_a.prec + g_dot - 1)
	{
		if (g_calc_num[g_i] > 4)
			g_calc_num[g_i - 1]++;
		g_calc_num[g_i] = 0;
		g_i--;
	}
	while (g_i > 0)
	{
		if (g_calc_num[g_i] > 9)
		{
			g_calc_num[g_i - 1]++;
			g_calc_num[g_i] = 0;
		}
		g_i--;
	}
}

static void		add_to_char_arr(char **num)
{
	g_i = 0;
	g_j = 0;
	ALLOC(*num, char*, sizeof(char) * (g_min + g_dot + g_a.prec + 1));
	(*num)[g_min + g_dot + g_a.prec] = '\0';
	if (g_min)
		(*num)[g_j++] = '-';
	while (g_i < g_dot)
	{
		if (g_calc_num[g_i] > 9)
			(*num)[g_j++] = g_calc_num[g_i] / 10 + '0';
		(*num)[g_j++] = g_calc_num[g_i++] % 10 + '0';
	}
	if (g_a.prec || (!g_a.prec && g_a.flags[4] == '#'))
		(*num)[g_j++] = '.';
	while (g_i - g_dot < g_a.prec)
	{
		if (g_i >= ALLOC_SIZE)
		{
			(*num)[g_j++] = '0';
			g_i++;
		}
		else
			(*num)[g_j++] = g_calc_num[g_i++] % 10 + '0';
	}
}

void			in_double(char **num, long double f)
{
	if (f < 0)
	{
		g_min = 1;
		f = -f;
	}
	else
		g_min = 0;
	if (g_a.prec == -1)
		g_a.prec = 6;
	ALLOC(g_calc_num, int*, sizeof(int) * ALLOC_SIZE);
	g_big = ft_itoa((int)f);
	g_i = 0;
	while (g_big[g_i] != '\0')
	{
		g_calc_num[g_i] = g_big[g_i] - '0';
		g_i++;
	}
	g_dot = g_i;
	f -= (int)f;
	add_to_int_arr(f);
	add_to_char_arr(num);
	free(g_calc_num);
}
