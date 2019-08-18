/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 12:43:36 by gdamion-          #+#    #+#             */
/*   Updated: 2019/08/18 14:37:44 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s_new;
	size_t	i;
	size_t	j;

	if (!s1 || !s2 || !(s_new =
	(char*)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
	{
		s_new[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s_new[i] = s2[j];
		i++;
		j++;
	}
	s_new[i] = '\0';
	return (s_new);
}
