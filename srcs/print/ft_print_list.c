#include "../../incs/push_swap.h"

void	ft_print_list(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	if (!stack_a)
		return ;
	printf("nbr = %d\n", stack_a->nbr);
	stack_a = stack_a->next;
	while (stack_a->prev != tmp->prev)
	{
		printf("nbr = %d\n", stack_a->nbr);
		stack_a = stack_a->next;
	}
}