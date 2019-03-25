/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:34:39 by gdamion-          #+#    #+#             */
/*   Updated: 2019/03/25 10:55:38 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t i;

	if (!s1 || !s2)
		return (0);
	if (!n)
		return (1);
	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && i != n - 1)
		i++;
	if (s1[i] == s2[i])
		return (1);
	return (0);
}
