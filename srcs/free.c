#include "../incs/push_swap.h"

void	ft_free_list(t_stack **stack, int len)
{
	t_stack	*tmp;

	tmp = *stack;
	while (len--)
	{
		tmp = tmp->next;
		free(*stack);
		*stack = tmp;
	}
}

void	ft_free_dclist(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*last;

	tmp = stack;
	last = stack->prev;
	while (tmp != last)
	{
		tmp = tmp->next;
		free(stack);
		stack = tmp;
	}
	free(stack);
}

static void	ft_free_2dstr(char **str)
{
	int	i;

	i = -1;
	while (*(str + ++i))
		free(*(str + i));
	free(str);
}

void	ft_general_free(t_stacks *stacks)
{
	if (stacks->args)
		ft_free_2dstr(stacks->args);
	if (stacks->utils)
		free(stacks->utils);
	if (stacks->stack_a)
		ft_free_dclist(stacks->stack_a);
	/*if (stacks->stack_b)
		ft_free_dclist(stacks->stack_b);*/
}

