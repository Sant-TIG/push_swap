#include "../../incs/push_swap.h"

static void	ft_treat_three_especial_case_a(t_stack **stack_a, t_stack **stack_b, t_pushswap **utils, int len)
{
	t_stack	*last;

	last = *stack_a;
	while (--len)
		last = last->next;
	if ((*stack_a)->nbr < (*stack_a)->next->nbr && (*stack_a)->nbr < last->nbr) //1 3 2
	{
		ft_push_b(stack_a, stack_b, utils);
		ft_swap_a(stack_a);
		ft_push_a(stack_a, stack_b, utils);
	}
	else if ((*stack_a)->nbr > (*stack_a)->next->nbr && (*stack_a)->nbr < last->nbr)//2 1 3
		ft_swap_a(stack_a);
	else if ((*stack_a)->nbr < (*stack_a)->next->nbr && (*stack_a)->nbr > last->nbr)//2 3 1
	{
		ft_push_b(stack_a, stack_b, utils);
		ft_swap_a(stack_a);
		ft_push_a(stack_a, stack_b, utils);
		ft_swap_a(stack_a);
	}
	else if ((*stack_a)->nbr > (*stack_a)->next->nbr && (*stack_a)->nbr > last->nbr && (*stack_a)->next->nbr > last->nbr)//3 2 1
	{
		ft_swap_a(stack_a);
		ft_rotate_a(stack_a);
		ft_rotate_a(stack_a);
		ft_push_b(stack_a, stack_b, utils);
		ft_reverse_rotate_a(stack_a);
		ft_reverse_rotate_a(stack_a);
		ft_push_a(stack_a, stack_b, utils);
	}
	else if ((*stack_a)->nbr > (*stack_a)->next->nbr && (*stack_a)->nbr > last->nbr)//3 2 1
	{
		ft_swap_a(stack_a);
		ft_push_b(stack_a, stack_b, utils);
		ft_swap_a(stack_a);
		ft_push_a(stack_a, stack_b, utils);
	}
}

static int	ft_specific_cases_a(t_stack	**stack_a, t_stack **copy,int len)
{
	if (!ft_check_sorted(*copy))
		return (0);
	else if (len == 2)
	{
		ft_swap_a(stack_a);
		return ;
	}
	else if (len == 3 && utils->stacka_len == 3)
	{
		ft_treat_three_case(stack_a);
		return ;
	}
}

void	ft_sort_a(t_stack **stack_a, t_stack **stack_b, t_pushswap *utils, int len)
{
	t_stack	*copy;
	t_stack	*tmp;
	int		pivot;
	int		max_push;

	copy = NULL;
	tmp = *stack_a;
	ft_copy_list(&copy, *stack_a, len);
	if (!ft_check_sorted(copy))
		return ;
	if (len == 2)
	{
		ft_swap_a(stack_a);
		return ;
	}
	else if (len == 3 && utils->stacka_len == 3)
	{
		ft_treat_three_case(stack_a);
		return ;
	}
	else if (len == 3)
	{
		ft_treat_three_especial_case_a(stack_a, stack_b, &utils, len);
		return ;
	}
	pivot = ft_quick_sort(&copy, 1, len);
	max_push = len / 2;
	int len1 = len / 2;
	len = len / 2 + len % 2;
	int	i = 0;
	while (max_push)
	{
		if (tmp->nbr < pivot)
		{
			tmp = tmp->next;
			ft_push_b(stack_a, stack_b, &utils);
			max_push--;
		}
		else
		{
			tmp = tmp->next;
			ft_rotate_a(stack_a);
			i++;
		}
	}
	if (len != utils->stacka_len && utils->stacka_len > 3)
	{
		while (i--)
			ft_reverse_rotate_a(stack_a);
	}
	ft_sort_a(stack_a, stack_b, utils, len);
	ft_sort_b(stack_a, stack_b, utils, len1);
}