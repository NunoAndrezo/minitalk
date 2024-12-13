/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneves-a <nneves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:25:38 by nneves-a          #+#    #+#             */
/*   Updated: 2024/09/09 18:45:24 by nneves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include "printf/ft_printf.h"
# include "libft/libft.h"

typedef struct s_server
{
	int		len;
	int		letters;
	int		binary_to_num;
	int		bit;
	char	*word;
}			t_server;

void	ft_decript_binary(t_server *l);
void	ft_handler(int signal, siginfo_t *s, void *c);
void	ft_handler_helper(t_server *l, siginfo_t *s);
int		main(int ac, char **av);

#endif
