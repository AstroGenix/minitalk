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

void	err(char *str)
{
	write(1, str, ft_strlen(str));
	write(1,"\n", 1);
	exit(0);
}
void	check_args(int argn, char *args[])
{
	int	i;

	i = 0;
	if (argn != 3)
		err("Incorret number of arguments.");
	while (args[1][i])
	{
		if (ft_isdigit(args[1][i]) == 0)
			err("Incorrect PID.");
		i++;
	}
	if (!args[2][0])
		err("No message was writen!");
}

int	main(int argn, char *args[])
{
    check_args(argn, args);
	return (0);
}