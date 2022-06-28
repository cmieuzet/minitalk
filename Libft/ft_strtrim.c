/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmieuzet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:16:26 by cmieuzet          #+#    #+#             */
/*   Updated: 2022/04/13 17:27:28 by cmieuzet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_start_match(char const *s1, char const *s2)
{
	int	i;

	i = 0;
	while (ft_strchr(s2, s1[i]))
		i++;
	return (i);
}

static int	ft_end_match(char const *s1, char const *s2)
{
	int	i;

	i = ft_strlen(s1);
	while (ft_strchr(s2, s1[i]))
		i--;
	return (ft_strlen(s1) - i);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;

	if (!s1 || !set)
		return (NULL);
	i = ft_strlen(s1) - ft_start_match(s1, set) - ft_end_match(s1, set);
	return (ft_substr(s1, ft_start_match(s1, set), i + 1));
}
