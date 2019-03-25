/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 11:55:18 by gdamion-          #+#    #+#             */
/*   Updated: 2019/03/25 10:55:12 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*new_s;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	if (!(new_s = (char*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		if (f((((char*)s)[i])))
		{
			new_s[j] = f((((char*)s)[i]));
			j++;
		}
		i++;
	}
	new_s[j] = '\0';
	return (new_s);
}
