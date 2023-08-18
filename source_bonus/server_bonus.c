/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:55:56 by dberehov          #+#    #+#             */
/*   Updated: 2023/08/17 09:55:58 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	user_sig(int signo, siginfo_t *newact, void *oldact)
{
	static int	bit;
	static int	c;

	(void)oldact;
	if (signo == SIGUSR1)
		c += 1 << (7 - bit);
	bit++;
	if (bit == 8)
	{
		write (1, &c, 1);
		kill(newact->si_pid, SIGUSR2);
		bit = 0;
		c = 0;
	}
}

int	main(int argn, char *args[])
{
	int					pid;
	struct sigaction	s_sig;

	pid = getpid();
	write(1, "PID: [", 6);
	write(1, "\e[1m", 4);
	ft_putnbr_fd(pid, 1);
	write(1, "\e[0m", 4);
	write(1, "]\n", 2);
	s_sig.sa_sigaction = &user_sig;
	s_sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &s_sig, NULL) == -1)
		print_err("Server: SIGUSR1 failed setup");
	if (sigaction(SIGUSR2, &s_sig, NULL) == -1)
		print_err("Server: SIGUSR2 failed setup");
	while (true)
		pause();
	return (0);
}
