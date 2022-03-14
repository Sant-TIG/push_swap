/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:54:21 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/03 15:05:19 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static int	ft_check_sorted2(t_stack *stack_a)
{
	t_stack	*last;

	last = stack_a->prev;
	if (stack_a != stack_a->next)//comprobamos que la lista es de mas de un numero
	{
		while (stack_a->nbr > stack_a->next->nbr && stack_a != last)
			stack_a = stack_a->next;
		return (stack_a != last);
	}
	return (0);
}

static void	ft_copy_list(t_stack *stack, t_stack **tmp, int len)
{
	int	nbr;
	int	pos;

	pos = 1;
	nbr = stack->nbr;
	ft_insert_nbr(stack->nbr, pos++, tmp, len);
	stack = stack->next;
	while (stack->nbr != nbr)
	{
		ft_insert_nbr(stack->nbr, pos++, tmp, len);
		stack = stack->next;
	}
}

static void	ft_sort_b(t_stack **stack_a, t_stack **stack_b, t_pushswap *utils)
{
	t_stack	*tmp1;

	tmp1 = *stack_b;
	if (!ft_check_sorted2(*stack_b))
	{
		while (tmp1->next != *stack_a)
			ft_push_a(stack_a, stack_b, &utils);
		return ;
	}
	if (utils->stackb_len == 2)
	{
		ft_swap_b(stack_b);
		ft_push_a(stack_a, stack_b, &utils);
		ft_push_a(stack_a, stack_b, &utils);
		return ;
	}
}

static void	ft_treat_three_case(t_stack **stack_a)
{
	//printf("treat three case\n");
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

static void	ft_sort_a(t_stack **stack_a, t_stack **stack_b, t_pushswap *utils)
{
	int	len;
	int	pivot;
	t_stack	*tmp;
	t_stack	*tmp1;
	
	tmp = NULL;
	tmp1 = *stack_a;
	ft_copy_list(*stack_a, &tmp, utils->stacka_len);
	len = (utils->stacka_len) - (((utils->stacka_len) / 2) + ((utils->stacka_len) % 2));
	if (!ft_check_sorted(*stack_a))
		return ;
	if (utils->stacka_len == 2)
	{
		ft_swap_a(stack_a);
		return ;
	}
	else if (utils->stacka_len == 3)
	{
		ft_treat_three_case(stack_a);
		return ;
	}
	pivot = ft_quick_sort(&tmp, 1, utils->stacka_len);
	while (len)
	{
		if (tmp1->nbr < pivot)
		{
			ft_push_b(stack_a, stack_b, &utils);
			len--;
		}
		else
			ft_rotate_a(stack_a);
		tmp1 = tmp1->next;
	}
	ft_sort_a(stack_a, stack_b, utils);
	ft_sort_b(stack_a, stack_b, utils);
}

static void	ft_push_swap(t_stack **stack_a, t_pushswap *utils)
{
	t_stack	*stack_b;

	stack_b = NULL;
	utils->stackb_len = 0;
	if (utils->stacka_len == 2)
		ft_rotate_a(stack_a);
	else if (utils->stacka_len == 3)
		ft_treat_three_case(stack_a);
	else
		ft_sort_a(stack_a, &stack_b, utils);
}

static int	ft_treat_args(char **args, t_stack **stack_a, t_pushswap *utils)
{
	int	pos;

	pos = 1;
	if (!ft_check_args(args))
	{
		printf("Error1\n");
		return (0);
	}
	while (*args)
		ft_insert_nbr(ft_atoi(*args++), pos++, stack_a, utils->stacka_len++);
	//ft_print_list(*stack_a);
	utils->stacka_len = ft_listlen(*stack_a);
	if (!ft_check_list(*stack_a, utils))
	{
		printf("Error2\n");
		return (0);
	}
	if (!ft_check_sorted(*stack_a))
		return (0);
	printf("Non sorted\n");
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_pushswap	utils;
	char	**args;

	stack_a = NULL;
	if (argc > 1)
	{
		argv++;
		if (argc == 2)
		{
			args = ft_split(*argv, ' ');
			if (!ft_treat_args(args, &stack_a, &utils))
				return (0);
			ft_print_list(stack_a);
			ft_push_swap(&stack_a, &utils);
			printf("stack_a\n");
			ft_print_list(stack_a);

		}
		else
		{
      		if (!ft_treat_args(argv, &stack_a, &utils))
        		return (0);
		}
	}
	return (0);
}
