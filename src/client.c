/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneves-a <nneves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:25:44 by nneves-a          #+#    #+#             */
/*   Updated: 2024/09/09 18:45:25 by nneves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	ft_main_helper(void)
{
	ft_printf("Error: Wrong format.\n");
	ft_printf("Try the following: ./client <PID> <MESSAGE>\n");
	exit(0);
}

void	ft_handler(int signal)
{
	if (signal == SIGUSR1)
	{
		ft_printf("Message received from server\n");
		exit(0);
	}
}

void	ft_send_phrase(char *s, int pid)
{
	int	bits_of_char;
	int	i;

	i = 0;
	while (s[i])
	{
		bits_of_char = 0;
		while (bits_of_char < 8)
		{
			if (s[i] & (1 << bits_of_char))
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			bits_of_char++;
			usleep(60000);
		}
		i++;
	}
}

void	ft_send_len(int len, int pid)
{
	int	num;
	int	x;

	num = 0;
	x = 0;
	while (num < 32)
	{
		if (len & (1 << num))
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		num++;
		usleep(60000);
	}
}

int	main(int ac, char **av)
{
	int	pid;
	int	strlen;

	if (ac == 3)
	{
		signal(SIGUSR1, ft_handler);
		signal(SIGUSR2, ft_handler);
		pid = ft_atoi(av[1]);
		strlen = ft_strlen(av[2]);
		if (pid <= 0 || kill(pid, 0) != 0 || strlen <= 0)
		{
			ft_printf("Error: Wrong PID or please write a real message.\n");
			return (1);
		}
		ft_send_len(strlen, pid);
		ft_send_phrase(av[2], pid);
		while (1)
			pause();
	}
	else
		ft_main_helper();
	return (0);
}
