/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:46:31 by dberehov          #+#    #+#             */
/*   Updated: 2023/05/20 14:46:32 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

// C libraries
# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <stdbool.h>

// 42 libraries
# include "../libft/libft.h"

// Utilities
void	print_err(char *str);
void	util_param(void);

#endif