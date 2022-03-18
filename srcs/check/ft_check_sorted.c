#include "../../incs/push_swap.h"

int	ft_check_sorted(t_stack *stack_a)
{
	t_stack	*last;

	last = stack_a->prev;
	if (stack_a != stack_a->next)
	{
		while (stack_a->nbr < stack_a->next->nbr && stack_a != last)
			stack_a = stack_a->next;
		return (stack_a != last);
	}
	return (0);
}