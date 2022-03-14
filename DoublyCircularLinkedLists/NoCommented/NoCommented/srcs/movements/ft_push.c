#include "../../incs/push_swap.h"

void	ft_push_a(t_stack **stack_a, t_stack **stack_b, t_pushswap **utils)
{
	t_stack	*curr;
	t_stack	*prev_1;
	int		nbrtmp;

	curr = *stack_b;
	nbrtmp = (*stack_b)->nbr;
	prev_1 = (*stack_b)->prev;
	*stack_b = (*stack_b)->next;
	prev_1->next = *stack_b;
	(*stack_b)->prev = prev_1;
	free(curr);
	ft_insert_begin(nbrtmp, stack_a);
	(*utils)->stacka_len++;
	(*utils)->stackb_len--;
	printf("pa\n");
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b, t_pushswap **utils)
{
	t_stack	*curr;
	t_stack	*prev_1;
	int		nbrtmp;

	curr = *stack_a;
	nbrtmp = (*stack_a)->nbr;
	prev_1 = (*stack_a)->prev;
	*stack_a = (*stack_a)->next;
	prev_1->next = *stack_a;
	(*stack_a)->prev = prev_1;
	free(curr);
	ft_insert_begin(nbrtmp, stack_b);
	(*utils)->stacka_len--;
	(*utils)->stackb_len++;
	printf("pb\n");
}