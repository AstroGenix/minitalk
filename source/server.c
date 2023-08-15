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

// Display PID - getpid()

void	sig_handle(int sighup, siginfo_t newact, siginfo_t oldact)
{
	static int	bit;
	static char	c;

	bit = -1;
	if (bit < 0)
		bit = 7;
	if (sighup == SIGUSR1)
		c |= (1 << bit);
	bit--;
	if (bit < 0 && c)
	{
		ft_putchar_fd(c, 1);
		c = 0;
		if (kill(newact->si_pid, SIGUSR2) == -1)
			print_err("Server failed so send SIGUSR2 signal.");
		return ;
	}
	if (kill(newact->si_pid, SIGUSR1) == -1)
		print_err("Server failed so send SIGUSR1 signal.");
}

int	main(int argn, char *args[])
{
	int					pid;
	struct sigaction	sa_sig;

	pid = getpid();
	write(1, "PID: [", 6);
	ft_putnbr_fd(pid, 1);
	write(1,"]\n", 2);
	while (true)
	{
		sa_sig.sa_sigaction = &sig_handle;
		sa_sig.sa_flags = SA_SIGINFO;
		if (sigaction(SIGURSR1, &sa_sig, NULL) == -1)
			print_err("Unable to send SIGUSR1 signal.");
		if (sigaction(SIGURSR2, &sa_sig, NULL) == -1)
			print_err("Unable to send SIGUSR2 signal.");
	}
	return (0);
}