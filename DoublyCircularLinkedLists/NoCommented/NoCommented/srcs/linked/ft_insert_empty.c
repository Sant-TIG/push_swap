#include "../../incs/push_swap.h"

void	ft_insert_empty(int nbr, t_stack **stack)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->nbr = nbr;
	new->prev = new;
	new->next = new;
	*stack = new;
}