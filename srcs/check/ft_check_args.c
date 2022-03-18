#include "../../incs/push_swap.h"

int	ft_check_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i] && ft_digit_str(args[i]))
		i++;
	return (!args[i]);
}