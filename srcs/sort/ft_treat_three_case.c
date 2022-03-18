#include "../../incs/push_swap.h"

void	ft_treat_three_case(t_stack **stack_a)
{
	if ((*stack_a)->nbr > (*stack_a)->next->nbr && (*stack_a)->nbr < (*stack_a)->prev->nbr)
		ft_swap_a(stack_a);
	else if ((*stack_a)->nbr > (*stack_a)->next->nbr && (*stack_a)->nbr > (*stack_a)->prev->nbr && (*stack_a)->next->nbr < (*stack_a)->prev->nbr)
		ft_rotate_a(stack_a);
	else if ((*stack_a)->nbr < (*stack_a)->next->nbr && (*stack_a)->nbr > (*stack_a)->prev->nbr)
		ft_reverse_rotate_a(stack_a);
	else if ((*stack_a)->nbr > (*stack_a)->next->nbr && (*stack_a)->nbr > (*stack_a)->prev->nbr && (*stack_a)->next->nbr > (*stack_a)->prev->nbr)
	{
		ft_rotate_a(stack_a);
		ft_swap_a(stack_a);
	}  
	else if ((*stack_a)->nbr < (*stack_a)->next->nbr && (*stack_a)->nbr < (*stack_a)->prev->nbr)
	{
		ft_reverse_rotate_a(stack_a);
		ft_swap_a(stack_a);
	}
}