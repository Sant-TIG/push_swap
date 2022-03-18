#include "../../incs/push_swap.h"

void	ft_insert_end(int nbr, t_stack **stack)
{
	t_stack	*new;
	t_stack	*last;

	if (!*stack)
	{
		ft_insert_empty(nbr, stack);
		return ;
	}
	last = (*stack)->prev;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->nbr = nbr;
	new->prev = last;
	new->next = *stack;
	(*stack)->prev = new;
	last->next = new;
}