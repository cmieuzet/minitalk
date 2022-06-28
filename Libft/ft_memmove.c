/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmieuzet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:00:09 by cmieuzet          #+#    #+#             */
/*   Updated: 2022/04/07 15:38:36 by cmieuzet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*tmpdest;
	char	*tmpsrc;

	tmpdest = (char *)dest;
	tmpsrc = (char *)src;
	if (tmpdest > tmpsrc)
		while (n--)
			tmpdest[n] = tmpsrc[n];
	else
		ft_memcpy(tmpdest, tmpsrc, n);
	return (dest);
}
