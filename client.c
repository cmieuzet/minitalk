/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmieuzet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:22:04 by cmieuzet          #+#    #+#             */
/*   Updated: 2022/06/06 21:19:19 by cmieuzet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	ft_send_byte(pid_t pid, int c, int byte)
{
	int	i;

	i = 0;
	while (i < byte)
	{
		if (c & 0x01)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c >>= 1;
		i++;
		usleep(50);
	}
}

static void	ft_send(pid_t pid, char *str)
{
	int	i;

	i = 0;
	ft_send_byte(pid, ft_strlen(str), 32);
	while (str[i])
	{
		ft_send_byte(pid, str[i], 8);
		i++;
	}
	ft_send_byte(pid, '\0', 8);
}

int	main(int argc, char **argv)
{
	pid_t	pid;

	if (argc != 3)
	{
		ft_putendl_fd("[\e[31mERROR\e[39m] Usage: ./client <PID> <message>", 1);
		return (0);
	}
	if (ft_strlen(argv[2]) == 0)
	{
		ft_putendl_fd("[\e[31mERROR\e[39m] Empty message", 1);
		return (0);
	}
	pid = ft_atoi(argv[1]);
	ft_send(pid, argv[2]);
	return (0);
}
