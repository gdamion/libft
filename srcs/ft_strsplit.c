/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <gdamion-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:55:12 by gdamion-          #+#    #+#             */
/*   Updated: 2018/12/04 17:35:32 by gdamion-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_splitcnt(char const *s, char c)
{
	size_t i;
	size_t count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i] != '\0')
		{
			if (s[i + 1] == c || s[i + 1] == '\0')
				count++;
			i++;
		}
	}
	return (count);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**str;

	if (!s || !c)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * ft_splitcnt(s, c) + 1)))
		return (NULL);
	i = 0;
	j = 0;
	k = 0;
	while (s[i])
	{
        while (s[i] == c)
            i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			str[k++] = ft_strndup(s + j, i - j);
	}
	str[k] = 0;
	return (str);
}
