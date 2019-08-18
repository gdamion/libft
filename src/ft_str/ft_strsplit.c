/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gdamion- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 14:55:12 by gdamion-          #+#    #+#             */
/*   Updated: 2019/08/18 14:37:44 by gdamion-         ###   ########.fr       */
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

static char		**ft_freeall(char **str)
{
	size_t i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		str[i] = NULL;
		i++;
	}
	free(str);
	str = NULL;
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**str;

	if (!s)
		return (NULL);
	if (!(str = (char **)malloc(sizeof(char *) * ft_splitcnt(s, c) + 1)))
		return (NULL);
	i = 0;
	k = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		if (i > j)
			if (!(str[k++] = ft_strndup(s + j, i - j)))
				return (ft_freeall(str));
	}
	str[k] = NULL;
	return (str);
}
