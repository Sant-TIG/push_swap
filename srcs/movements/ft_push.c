#include "../../incs/push_swap.h"

void	ft_push_a(t_stack **stack_a, t_stack **stack_b, t_pushswap **utils)
{
	t_stack	*tmp;
	int		nbr;

	tmp = *stack_b;
	nbr = tmp->nbr;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = tmp->prev;
	tmp->prev->next = (*stack_b);
	free(tmp);
	ft_insert_begin(nbr, stack_a);
	(*utils)->stacka_len++;
	(*utils)->stackb_len--;
	write(1, "pa\n", 3);
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b, t_pushswap **utils)
{

	t_stack	*tmp;
	int		nbr;

	tmp = *stack_a;
	nbr = tmp->nbr;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = tmp->prev;
	tmp->prev->next = (*stack_a);
	free(tmp);
	ft_insert_begin(nbr, stack_b);
	(*utils)->stacka_len--;
	(*utils)->stackb_len++;
	write(1, "pb\n", 3);
}