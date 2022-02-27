#include "../../incs/push_swap.h"



int	ft_check_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i] && ft_strdigit(args[i]))
		i++;
	if (args[i])
			return (0);
	return (1);
}