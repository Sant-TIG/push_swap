#include "../../incs/push_swap.h"

int	ft_check_list(t_stack *stack_a, t_pushswap *utils)
{
	t_stack	*last;
	t_stack	*tmp1;
	int		len;

	len = utils->stacka_len;
	last = stack_a->prev;
	tmp1 = stack_a;
	while (--len)
	{
		tmp1 = tmp1->next;
		while (tmp1->prev != last)
		{
			if (stack_a->nbr == tmp1->nbr)
				return (0);
			tmp1 = tmp1->next;
		}
		stack_a = stack_a->next;
		tmp1 = stack_a;
	}
	return (1);
}