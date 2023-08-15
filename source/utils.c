#include "../include/minitalk.h"

void	print_err(char *str)
{
	write(1, str, ft_strlen(str));
	write(1,"\n", 1);
	exit(1);
}

