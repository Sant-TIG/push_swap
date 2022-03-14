#include "../../incs/push_swap.h"

void	ft_reverse_rotate_a(t_stack **stack_a)
{
	*stack_a = (*stack_a)->prev;
	printf("rra\n");
}

void	ft_reverse_rotate_b(t_stack **stack_b)
{
	*stack_b = (*stack_b)->prev;
	printf("rrb\n");
}

void	ft_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate_a(stack_a);
	ft_reverse_rotate_b(stack_b);
	printf("rrr\n");
}