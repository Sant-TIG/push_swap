#include "../../incs/push_swap.h"

void	ft_print_args(char **args)
{
	int	i;
	i = -1;
	while (args[++i])
	{
		printf("arg[%d] %s\n", i, args[i]);
	}
}