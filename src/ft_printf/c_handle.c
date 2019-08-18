/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_handle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 21:00:31 by gdamion-          #+#    #+#             */
/*   Updated: 2019/08/18 16:50:01 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	c_actions(char c)
{
	int i;

	if (g_a.flags[3] == '-')
	{
		PRINT(c);
		i = 1;
		while (i++ < g_a.width)
		{
			PRINT(' ');
		}
		g_printed--;
	}
	else
	{
		i = 0;
		while (i++ < g_a.width - 1)
		{
			PRINT(' ');
		}
		PRINT(c);
		g_printed--;
	}
}

void		c_process(void)
{
	char c;

	c = (char)va_arg(g_ap, int);
	if (g_a.width > 1)
		c_actions(c);
	else
		PRINT(c);
}
