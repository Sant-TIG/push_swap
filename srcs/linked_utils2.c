#include "../incs/push_swap.h"

void	ft_insert_nbr(int nbr, int pos, t_stack **stack, int stack_len, t_stacks *stacks)
{
	t_stack	*new;
	t_stack	*tmp;

	if (!*stack)
		ft_insert_empty_push(nbr, stack, stacks);
	else if (pos == 1)
		ft_insert_begin(nbr, stack, stacks);
	else if (pos == stack_len)
		ft_insert_end_push(nbr, stack, stacks);
	else
	{
		tmp = *stack;
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
			return ;
		while (--pos)
			tmp = tmp->next;
		new->nbr = nbr;
		new->prev = tmp->prev;
		new->next = tmp;
		tmp->prev->next = new;
		tmp->prev = new;
	}
}