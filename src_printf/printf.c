/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 12:44:37 by gdamion-          #+#    #+#             */
/*   Updated: 2019/03/25 10:59:17 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int	g_i;

void		clean_all(void)
{
	ft_bzero(g_a.flags, sizeof(char) * 5);
	g_a.width = 0;
	g_a.prec = -1;
	ft_bzero(g_a.length, 3);
	g_a.type = 0;
}

void		arg_found(char **f)
{
	clean_all();
	add_flags(f, &g_i);
	add_width(f, &g_i);
	add_prec(f, &g_i);
	add_length(f, &g_i);
	if ((*f)[g_i] == 'c' || (*f)[g_i] == 's' || (*f)[g_i] == 'p' ||
		(*f)[g_i] == 'd' || (*f)[g_i] == 'i' || (*f)[g_i] == 'o' ||
		(*f)[g_i] == 'u' || (*f)[g_i] == 'x' || (*f)[g_i] == 'X' ||
		(*f)[g_i] == 'f' || (*f)[g_i] == '%')
	{
		g_a.type = (*f)[g_i];
		g_i++;
	}
	(g_a.type == 'c') ? c_process() : 0;
	(g_a.type == 's') ? s_process() : 0;
	(g_a.type == 'p') ? p_process() : 0;
	(g_a.type == 'd' || g_a.type == 'i') ? d_i_process() : 0;
	(g_a.type == 'o') ? o_process() : 0;
	(g_a.type == 'u') ? u_process() : 0;
	(g_a.type == 'x') ? x_process(0) : 0;
	(g_a.type == 'X') ? x_process(1) : 0;
	(g_a.type == 'f') ? f_process() : 0;
	(g_a.type == '%') ? proc_process() : 0;
}

int			ft_printf(const char *restrict format, ...)
{
	char *f;

	f = (char*)format;
	g_printed = 0;
	va_start(g_ap, format);
	g_i = 0;
	while (f[g_i] != '\0')
	{
		if (f[g_i] == '%')
			arg_found(&f);
		else
		{
			ft_putchar(f[g_i++]);
			g_printed++;
		}
	}
	va_end(g_ap);
	return (g_printed);
}
