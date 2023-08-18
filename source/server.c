/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:39:51 by dberehov          #+#    #+#             */
/*   Updated: 2023/05/20 15:39:53 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	user_sig(int signo)
{
	static int	bit;
	static int	c;
	int			i;

	if (signo == SIGUSR1)
		i = 1;
	else
		i = 0;
	c = (c << 1) + i;
	bit++;
	if (bit == 8)
	{
		write(1, &c, 1);
		bit = 0;
		c = 0;
	}
}

int	main(int argn, char *args[])
{
	int	pid;

	pid = getpid();
	write(1, "PID: [", 6);
	write(1, "\e[1m", 4);
	ft_putnbr_fd(pid, 1);
	write(1, "\e[0m", 4);
	write(1, "]\n", 2);
	signal(SIGUSR1, user_sig);
	signal(SIGUSR2, user_sig);
	while (true)
		pause ();
	return (0);
}
