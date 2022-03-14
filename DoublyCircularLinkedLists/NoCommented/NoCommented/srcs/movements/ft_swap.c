#include "../../incs/push_swap.h"

void	ft_swap_a(t_stack **stack_a)
{
	int	tmp;

	tmp = (*stack_a)->nbr;
	(*stack_a)->nbr = (*stack_a)->next->nbr;
	(*stack_a)->next->nbr = tmp;
	printf("sa\n");
}

void	ft_swap_b(t_stack **stack_b)
{
	int	tmp;

	tmp = (*stack_b)->nbr;
	(*stack_b)->nbr = (*stack_b)->next->nbr;
	(*stack_b)->next->nbr = tmp;
	printf("sb\n");
}

void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap_a(stack_a);
	ft_swap_b(stack_b);
	printf("ss\n");
}