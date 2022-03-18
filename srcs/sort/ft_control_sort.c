#include "../../incs/push_swap.h"

void	ft_control_sort(t_stack **stack_a, t_pushswap *utils)
{
	t_stack	*stack_b;

	stack_b = NULL;
	utils->stackb_len = 0;
	if (utils->stacka_len == 2)
		ft_rotate_a(stack_a);
	else if (utils->stacka_len == 3)
		ft_treat_three_case(stack_a);
	else
		ft_sort_a(stack_a, &stack_b, utils, utils->stacka_len);
}