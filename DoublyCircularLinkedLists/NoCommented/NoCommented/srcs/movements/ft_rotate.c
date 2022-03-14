#include "../../incs/push_swap.h"

void	ft_rotate_a(t_stack **stack_a)
{
	*stack_a = (*stack_a)->next;
	printf("ra\n");
}

void	ft_rotate_b(t_stack **stack_b)
{
	*stack_b = (*stack_b)->next;
	printf("rb\n");
}

void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate_a(stack_a);
	ft_rotate_b(stack_b);
	printf("rr\n");
}