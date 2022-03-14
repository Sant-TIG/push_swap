#include "../../incs/push_swap.h"

void	ft_print_list(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	if (!stack_a)
		return ;
	//printf("direccion = %p nbr = %d prev = %p next = %p\n", stack_a, stack_a->nbr, stack_a->prev, stack_a->next);
	printf("nbr = %d\n", stack_a->nbr);
	stack_a = stack_a->next;
	while (stack_a->prev != tmp->prev)
	{
		//printf("direccion = %p nbr = %d prev = %p next = %p\n", stack_a, stack_a->nbr, stack_a->prev, stack_a->next);
		printf("nbr = %d\n", stack_a->nbr);
		stack_a = stack_a->next;
	}
}