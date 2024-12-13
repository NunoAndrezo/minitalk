/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneves-a <nneves-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/29 17:25:56 by nneves-a          #+#    #+#             */
/*   Updated: 2024/09/09 18:45:26 by nneves-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>
# include <stdio.h>
# include <signal.h>
# include <stdlib.h>
# include <string.h>
# include "libft/libft.h"
# include "printf/ft_printf.h"

void	ft_handler(int signal);
void	ft_send_phrase(char *s, int pid);
void	ft_send_len(int len, int pid);
int		main(int ac, char **av);
void	ft_main_helper(void);

#endif
