#include "../incs/push_swap.h"

void	ft_error_exit(t_stacks *stacks)
{
	write(1, "Error\n", 6);
	ft_general_free(stacks);
	exit (1);
}