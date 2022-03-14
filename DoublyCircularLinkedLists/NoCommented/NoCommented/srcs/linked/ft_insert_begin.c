#include "../../incs/push_swap.h"

/*
  NAME 
*/

void	ft_insert_begin(int nbr, t_stack **stack)
{
	t_stack	*new;
	t_stack	*last;

	if (!*stack)
		ft_insert_empty(nbr, stack);
	last = (*stack)->prev;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->nbr = nbr;
	new->prev = last;
	new->next = *stack;
	last->next= new;
	(*stack)->prev = new;
	(*stack) = new;
}