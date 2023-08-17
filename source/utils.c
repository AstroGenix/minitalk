/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 09:56:47 by dberehov          #+#    #+#             */
/*   Updated: 2023/08/17 09:56:48 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	print_err(char *str)
{
	util_param();
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(1);
}

void	util_param(void)
{
	write(1, "./client ", 9);
	write(1, "\033[1;32m", 7);
	write(1, "PID", 3);
	write(1, "\033[0m \"", 6);
	write(1, "\033[1;34m", 7);
	write(1, "Message here", 12);
	write(1, "\033[0m\"\n", 6);
}
