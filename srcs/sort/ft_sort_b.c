#include "../../incs/push_swap.h"

static int	ft_check_sorted2(t_stack *stack_b)
{
	t_stack	*last;

	last = stack_b->prev;
	if (stack_b != stack_b->next)//comprobamos que la lista es de mas de un numero
	{
		while (stack_b->nbr > stack_b->next->nbr && stack_b != last)
			stack_b = stack_b->next;
		return (stack_b != last);
	}
	return (0);
}


static void	ft_treat_three_special_case_b(t_stack **stack_a, t_stack **stack_b, t_pushswap **utils, int len)
{
	t_stack	*last;

	last = *stack_b;
	while (--len)
		last = last->next;
	if ((*stack_b)->nbr < (*stack_b)->next->nbr && (*stack_b)->nbr < last->nbr && (*stack_b)->next->nbr > last->nbr) //1 3 2
	{
		ft_swap_b(stack_b);
		ft_push_a(stack_a, stack_b, utils);
		ft_swap_b(stack_b);
		ft_push_a(stack_a, stack_b, utils);
		ft_push_a(stack_a, stack_b, utils);
	}
	else if ((*stack_b)->nbr > (*stack_b)->next->nbr && (*stack_b)->nbr < last->nbr)//2 1 3
	{
		ft_push_a(stack_a, stack_b, utils);
		ft_swap_b(stack_b);
		ft_push_a(stack_a, stack_b, utils);
		ft_swap_a(stack_a);
		ft_push_a(stack_a, stack_b, utils);
	}
	else if ((*stack_b)->nbr < (*stack_b)->next->nbr && (*stack_b)->nbr > last->nbr)//2 3 1
	{
		ft_swap_b(stack_b);
		ft_push_a(stack_a, stack_b, utils);
		ft_push_a(stack_a, stack_b, utils);
		ft_push_a(stack_a, stack_b, utils);
	}
	else if ((*stack_b)->nbr < (*stack_b)->next->nbr && (*stack_b)->nbr < last->nbr && (*stack_b)->next->nbr < last->nbr)//1 2 3
	{
		ft_swap_b(stack_b);
		ft_push_a(stack_a, stack_b, utils);
		ft_swap_b(stack_b);
		ft_push_a(stack_a, stack_b, utils);
		ft_swap_a(stack_a);
		ft_push_a(stack_a, stack_b, utils);
	}
	else if ((*stack_b)->nbr > (*stack_b)->next->nbr && (*stack_b)->nbr > last->nbr)//3 1 2
	{
		ft_push_a(stack_a, stack_b, utils);
		ft_swap_b(stack_b);
		ft_push_a(stack_a, stack_b, utils);
		ft_push_a(stack_a, stack_b, utils);
	}	
}

static void	ft_treat_three_case_b(t_stack **stack_a, t_stack **stack_b, t_pushswap **utils)
{
	if ((*stack_b)->nbr < (*stack_b)->next->nbr && (*stack_b)->nbr < (*stack_b)->prev->nbr && (*stack_b)->next->nbr > (*stack_b)->prev->nbr) //1 3 2
		ft_rotate_b(stack_b);
	else if ((*stack_b)->nbr > (*stack_b)->next->nbr && (*stack_b)->nbr < (*stack_b)->prev->nbr)//2 1 3
		ft_reverse_rotate_b(stack_b);
	else if ((*stack_b)->nbr < (*stack_b)->next->nbr && (*stack_b)->nbr > (*stack_b)->prev->nbr)//2 3 1
		ft_swap_b(stack_b);
	else if ((*stack_b)->nbr < (*stack_b)->next->nbr && (*stack_b)->nbr < (*stack_b)->prev->nbr)//1 2 3
	{
		ft_rotate_b(stack_b);
		ft_swap_b(stack_b);
	}
	else if ((*stack_b)->nbr > (*stack_b)->next->nbr && (*stack_b)->nbr > (*stack_b)->prev->nbr)//3 1 2
	{
		ft_reverse_rotate_b(stack_b);
		ft_swap_b(stack_b);
	}	
	ft_push_a(stack_a, stack_b, utils);
	ft_push_a(stack_a, stack_b, utils);
	ft_push_a(stack_a, stack_b, utils);
}

void	ft_sort_b(t_stack **stack_a, t_stack **stack_b, t_pushswap *utils, int len)
{
	t_stack	*copy;
	t_stack	*tmp;
	int		pivot;
	int		max_push;

	copy = NULL;
	tmp = *stack_b;
	ft_copy_list(&copy, *stack_b, len);
	if (!ft_check_sorted2(copy))
	{
		while (len--)
		{
			ft_push_a(stack_a, stack_b, &utils);
			copy = copy->next;
		}
		return ;
	}
	else if (len == 2)
	{
		ft_swap_b(stack_b);
		ft_push_a(stack_a, stack_b, &utils);
		ft_push_a(stack_a, stack_b, &utils);
		return ;
	}
	else if (len == 3 && utils->stackb_len == 3)
	{
		ft_treat_three_case_b(stack_a, stack_b, &utils);
		return ;
	}
	else if (len == 3)
	{
		ft_treat_three_special_case_b(stack_a, stack_b, &utils, len);
		return ;
	}
	pivot = ft_quick_sort(&copy, 1, len);
	max_push = len / 2 + len % 2;
	int len1 = len / 2;
	len = len / 2 + len % 2;
	int i = 0;
	while (max_push)
	{
		if (tmp->nbr >= pivot)
		{
			tmp = tmp->next;
			ft_push_a(stack_a, stack_b, &utils);
			max_push--;
		}
		else
		{
			tmp = tmp->next;
			ft_rotate_b(stack_b);
			i++;
		}
	}
	if (len != utils->stackb_len)
	{
		while (i--)
			ft_reverse_rotate_b(stack_b);
	}
	ft_sort_a(stack_a, stack_b, utils, len);
	ft_sort_b(stack_a, stack_b, utils, len1);
}