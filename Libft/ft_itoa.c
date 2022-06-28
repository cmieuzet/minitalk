/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmieuzet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 14:58:05 by cmieuzet          #+#    #+#             */
/*   Updated: 2022/04/14 14:21:44 by cmieuzet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_size_malloc(long nbr)
{
	int	len;

	len = 1;
	if (nbr < 0)
	{
		len++;
		nbr *= -1;
	}
	while (nbr > 9)
	{
		nbr /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	i;
	long	nb;

	if (n == 0)
		return (ft_strdup("0"));
	str = malloc(sizeof(char) * (ft_size_malloc(n) + 1));
	i = ft_size_malloc(n) - 1;
	nb = n;
	if (!str)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		nb *= -1;
	}
	while (nb > 0)
	{
		str[i] = (nb % 10 + '0');
		nb /= 10;
		i--;
	}	
	str[ft_size_malloc(n)] = '\0';
	return (str);
}
