/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmieuzet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 23:31:36 by cmieuzet          #+#    #+#             */
/*   Updated: 2022/04/18 14:54:36 by cmieuzet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_nbstr(char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			j++;
		while (s[i] != c && s[i])
			i++;
	}
	return (j);
}

static size_t	ft_lenstr(char const *s, char c, size_t start)
{
	size_t	len;

	len = 0;
	while (s[start] && s[start] != c)
	{
		start++;
		len++;
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	x;

	if (!s)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_nbstr(s, c) + 1));
	if (!tab)
		return (NULL);
	i = 0;
	x = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
		{
			tab[x] = ft_substr(s, i, ft_lenstr(s, c, i));
			x++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	tab[x] = NULL;
	return (tab);
}
