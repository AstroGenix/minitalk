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

void	user_sig(int signum, siginfo_t *info, void *ucontent)
{
	static int				bit_itr = -1;
	static unsigned char	c;

	if (bit_itr < 0)
		bit_itr = 7;
	if (signum == SIGUSR1)
		c |= (1 << bit_itr);
	bit_itr--;
	if (bit_itr < 0 && c)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		c = 0;
		if (kill(info->si_pid, SIGUSR2) == -1)
			print_err("Server failed to send SIGUSR2");
		return ;
	}
	if (kill(info->si_pid, SIGUSR1) == -1)
		print_err("Failed to send SIGUSR1");
}

int	main(int argn, char *args[])
{
	int					pid;
	struct sigaction	sa_sig;

	pid = getpid();
	write(1, "PID: [", 6);
	ft_putnbr_fd(pid, 1);
	write(1, "]\n", 2);
	
	while (true)
	{
		sa_sig.sa_sigaction = &user_sig;
		sa_sig.sa_flags = SA_SIGINFO;
		if (sigaction(SIGUSR1, &sa_sig, NULL) == -1)
			print_err("Unable to send SIGUSR1 signal.");
		if (sigaction(SIGUSR2, &sa_sig, NULL) == -1)
			print_err("Unable to send SIGUSR2 signal.");
	}
	return (0);
}
