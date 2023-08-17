/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 15:39:57 by dberehov          #+#    #+#             */
/*   Updated: 2023/05/20 15:39:59 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	check_args(int argn, char *args[])
{
	int	i;

	i = 0;
	if (argn != 3)
		print_err("Incorrect number of parameters.");
	while (args[1][i])
	{
		if (ft_isdigit(args[1][i]) == 0)
			print_err("Incorrect PID.");
		i++;
	}
	if (!args[2][0])
		print_err("Message field empty.");
}

void	transmit(int pid, char *str)
{
	unsigned char	c;
	int				bit;
	int				i;

	i = 0;
	while (str[i])
	{
		c = str[i];
		bit = 8;
		while (bit)
		{
			if (c & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(50);
			c <<= 1;
			bit--;
		}
		i++;
	}
}

void	config_signals(void)
{
	struct sigaction	sa_sig;

	sa_sig.sa_handler = SIG_IGN;
	sa_sig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_sig, NULL) == -1)
		print_err("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_sig, NULL) == -1)
		print_err("Failed to change SIGUSR2's behavior");
}

int	main(int argn, char *args[])
{
	pid_t	pid;

	check_args(argn, args);
	pid = ft_atoi(args[1]);
	config_signals();
	transmit(pid, args[2]);
	return (0);
}
