/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:55:52 by dberehov          #+#    #+#             */
/*   Updated: 2023/08/17 09:55:54 by dberehov         ###   ########.fr       */
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
			if ((c >> 7) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			c <<= 1;
			bit--;
		}
		i++;
	}
}

void	sig_letter(int signo)
{
	if (signo == SIGUSR2)
		write(1, "Character received.\n", 20);
}

int	main(int argn, char *args[])
{
	pid_t				pid;
	struct sigaction	s_sig;

	check_args(argn, args);
	pid = ft_atoi(args[1]);
	s_sig.sa_handler = &sig_letter;
	if (sigaction(SIGUSR1, &s_sig, NULL) == -1)
		print_err("Client: SIGUSR1 failed.");
	if (sigaction(SIGUSR2, &s_sig, NULL) == -1)
		print_err("Client: SIGUSR2 failed.");
	transmit(pid, args[2]);
	return (0);
}
