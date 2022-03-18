#include "../../incs/push_swap.h"

void	ft_copy_list(t_stack **tmp, t_stack *stack, int len)
{
	int	nbr;
	int	pos;

	pos = 1;
	nbr = stack->nbr;
	while (len--)
	{
		ft_insert_nbr(stack->nbr, pos++, tmp, len);
		stack = stack->next;
	}
}
