/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 11:56:59 by gdamion-          #+#    #+#             */
/*   Updated: 2019/03/25 11:06:39 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct	s_arg
{
	char		flags[5];
	size_t		width;
	int			prec;
	char		length[3];
	char		type;
}				t_arg;

t_arg			g_a;
va_list			g_ap;
int				g_printed;

# define PRINT(x) ft_putchar(x); g_printed++;
# define ALLOC(x, y, z) if(!(x = (y)malloc(z))) {ft_putendl("ERROR"); exit(0);}
# define ALLOC_SIZE 60

int				ft_printf(const char *restrict format, ...);
void			proc_process(void);
void			c_process(void);
void			s_process(void);
void			p_process(void);
void			d_i_process(void);
void			o_process(void);
void			u_process(void);
void			x_process(int var);
void			f_process(void);
char			*ft_abs_itoa_long(unsigned long long n);

void			add_flags(char **f, int *i);
void			add_width(char **f, int *i);
void			add_prec(char **f, int *i);
void			add_length(char **f, int *i);

void			in_double(char **num, long double f);
void			ulong_init(unsigned long long *a);
void			in_octave(char **dec, unsigned long long o);

void			x_minflag(unsigned long long x, int var, int numlen, char *num);
void			x_zeroflag(unsigned long long x,
							int var, int numlen, char *num);
void			x_noflag(unsigned long long x, int var, int numlen, char *num);

#endif
