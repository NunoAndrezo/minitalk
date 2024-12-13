/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneves-a <nneves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:25:32 by nneves-a          #+#    #+#             */
/*   Updated: 2024/09/09 18:45:22 by nneves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	ft_handler_helper(t_server *l, siginfo_t *s)
{
	if (l->len && l->len == l->letters)
	{
		ft_printf("%s\n", l->word);
		free(l->word);
		l->len = 0;
		l->letters = 0;
		l->binary_to_num = 0;
		l->word = NULL;
		kill(s->si_pid, SIGUSR1);
		l->bit = 0;
	}
	else if (l->len == 0 && l->word == NULL)
	{
		l->len = l->binary_to_num;
		l->binary_to_num = 0;
		l->word = (char *)ft_calloc(l->len + 1, sizeof(char));
		if (!l->word)
		{
			ft_printf("Failed to allocate memory for word\n");
			return ;
		}
		l->bit = 0;
	}
}

void	ft_decript_binary(t_server *l)
{
	static int	k;

	if (l->len > k)
	{
		l->word[k] = l->binary_to_num;
		k++;
		l->letters++;
	}
	if (l->len == k)
		k = 0;
	l->bit = 0;
	l->binary_to_num = 0;
}

void	ft_handler(int signal, siginfo_t *s, void *c)
{
	static t_server	list;

	c = NULL;
	if (list.len && list.len != list.letters)
	{
		if (signal == SIGUSR1 && list.bit < 8)
			list.binary_to_num |= 1 << list.bit;
		list.bit++;
		if (list.bit == 8)
			ft_decript_binary(&list);
	}
	else if (list.len == 0 && !list.word)
	{
		if (signal == SIGUSR1 && list.bit < 32)
			list.binary_to_num |= 1 << list.bit;
		list.bit++;
		if (list.bit == 32)
			ft_handler_helper(&list, s);
	}
	if (list.len && list.len == list.letters)
		ft_handler_helper(&list, s);
	kill(s->si_pid, SIGUSR2);
}

int	main(int ac, char **av)
{
	int					pid;
	struct sigaction	a;

	ft_bzero(&a, sizeof(struct sigaction));
	if (ac != 1 && av[0])
	{
		ft_printf("Error: Wrong format!\n");
		ft_printf("Try: ./server\n");
		return (0);
	}
	pid = getpid();
	ft_printf("PID: %d\n", pid);
	a.sa_flags = SA_SIGINFO;
	a.sa_sigaction = ft_handler;
	sigaction(SIGUSR2, &a, NULL);
	sigaction(SIGUSR1, &a, NULL);
	while (1)
		pause();
	return (0);
}
