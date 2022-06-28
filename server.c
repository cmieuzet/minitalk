/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmieuzet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:22:19 by cmieuzet          #+#    #+#             */
/*   Updated: 2022/06/06 20:56:57 by cmieuzet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_len(int signal)
{
	static int	i = 0;
	static int	len = 0;

	if (i == 32)
	{
		len = 0;
		i = 0;
	}
	if (signal == SIGUSR1)
		len |= (1 << i);
	else
		len |= (0 << i);
	i++;
	if (i == 32)
		return (len);
	return (0);
}

static char	ft_char(int signal)
{
	static int	i = 0;
	static char	octet = 0;

	if (i == 8)
	{
		octet = 0;
		i = 0;
	}
	if (signal == SIGUSR1)
		octet |= (1 << i);
	else
		octet |= (0 << i);
	i++;
	if (i == 8)
		return (octet);
	return (-1);
}

static char	*ft_convert(int signal, char *str)
{
	static int	i = 0;
	static char	char_octet = -1;

	char_octet = ft_char(signal);
	if (char_octet != -1)
	{
		if (char_octet == '\0')
		{
			ft_putstr_fd(str, 1);
			ft_putstr_fd("\n", 1);
			free (str);
			str = NULL;
			i = 0;
			char_octet = 0;
		}
		else
		{
			str[i] = char_octet;
			char_octet = 0;
			i++;
		}
	}
	return (str);
}

static void	ft_choice(int signal)
{
	static char	*str = NULL;
	static int	len = 0;

	if (!str)
	{
		len = ft_len(signal);
		if (len != 0)
		{
			str = malloc(sizeof(char) * (len + 1));
			str[len] = '\0';
			len = 0;
			if (!str)
				return ;
		}
	}
	else
		str = ft_convert(signal, str);
}

int	main(void)
{
	ft_putstr_fd("[\e[33mINFO\e[39m] Server Number PID: ", 1);
	ft_putnbr_fd(getpid(), 1);
	ft_putstr_fd("\n\n", 1);
	signal(SIGUSR1, ft_choice);
	signal(SIGUSR2, ft_choice);
	while (1)
		continue ;
	return (0);
}
