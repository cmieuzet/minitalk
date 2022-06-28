/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmieuzet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:57:47 by cmieuzet          #+#    #+#             */
/*   Updated: 2022/04/12 15:30:26 by cmieuzet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;
	size_t	j;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (start > ft_strlen(s))
	{
		dest = ft_calloc(1, sizeof(char));
		return (dest);
	}
	else if (len > ft_strlen(s) - start)
		j = ft_strlen(s) - start;
	else
		j = len;
	dest = malloc(sizeof(char) * j + 1);
	if (!dest)
		return (NULL);
	while (start < ft_strlen(s) && i < j)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}
