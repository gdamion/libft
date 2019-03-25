/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_read.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:48:46 by pcollio-          #+#    #+#             */
/*   Updated: 2019/03/25 11:05:18 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	add_flags(char **f, int *i)
{
	(*i)++;
	while (1)
	{
		if ((*f)[(*i)] == '0')
			g_a.flags[0] = (*f)[(*i)];
		else if ((*f)[(*i)] == ' ')
			g_a.flags[1] = (*f)[(*i)];
		else if ((*f)[(*i)] == '+')
			g_a.flags[2] = (*f)[(*i)];
		else if ((*f)[(*i)] == '-')
			g_a.flags[3] = (*f)[(*i)];
		else if ((*f)[(*i)] == '#')
			g_a.flags[4] = (*f)[(*i)];
		else
			break ;
		(*i)++;
	}
}

void	add_width(char **f, int *i)
{
	if ((g_a.width = ft_atoi(&((*f)[(*i)]))))
		while ('0' <= (*f)[(*i)] && (*f)[(*i)] <= '9')
			(*i)++;
	else if ((*f)[(*i)] == '*')
	{
		g_a.width = va_arg(g_ap, int);
		(*i)++;
	}
}

void	add_prec(char **f, int *i)
{
	if ((*f)[(*i)] == '.')
	{
		(*i)++;
		if ((g_a.prec = ft_atoi(&((*f)[(*i)]))))
			while ('0' <= (*f)[(*i)] && (*f)[(*i)] <= '9')
				(*i)++;
		else if ((*f)[(*i)] == '*')
		{
			g_a.prec = va_arg(g_ap, int);
			(*i)++;
		}
		else if ((*f)[(*i)] == '0')
		{
			g_a.prec = 0;
			(*i)++;
		}
		else
			g_a.prec = 0;
	}
}

void	add_length(char **f, int *i)
{
	if ((*f)[(*i)] == 'L')
	{
		g_a.length[0] = 'L';
		(*i)++;
	}
	else if ((*f)[(*i)] == 'l')
	{
		g_a.length[0] = 'l';
		if ((*f)[(*i) + 1] == 'l')
		{
			g_a.length[1] = 'l';
			(*i)++;
		}
		(*i)++;
	}
	else if ((*f)[(*i)] == 'h')
	{
		g_a.length[0] = 'h';
		if ((*f)[(*i) + 1] == 'h')
		{
			g_a.length[1] = 'h';
			(*i)++;
		}
		(*i)++;
	}
}
