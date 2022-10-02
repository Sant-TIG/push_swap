#include "../incs/push_swap.h"

void	ft_insert_empty_push(int nbr, t_stack **stack, t_stacks *stacks)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		ft_error_exit(stacks);
	new->nbr = nbr;
	new->prev = new;
	new->next = new;
	*stack = new;
}

void	ft_insert_end_push(int nbr, t_stack **stack, t_stacks *stacks)
{
	t_stack	*new;
	t_stack	*last;

	if (!*stack)
		ft_insert_empty_push(nbr, stack, stacks);
	else
	{
		last = (*stack)->prev;
		new = (t_stack *)malloc(sizeof(t_stack));
		if (!new)
			ft_error_exit(stacks);
		new->nbr = nbr;
		new->prev = last;
		new->next = *stack;
		(*stack)->prev = new;
		last->next = new;
	}
}

void	ft_insert_begin(int nbr, t_stack **stack, t_stacks *stacks)
{
	t_stack	*new;
	t_stack	*last;

	if (!*stack)
	{
		ft_insert_empty_push(nbr, stack, stacks);
		return ;
	}
	last = (*stack)->prev;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->nbr = nbr;
	new->prev = last;
	new->next = *stack;
	last->next = new;
	(*stack)->prev = new;
	(*stack) = new;
}

int	ft_listlen(t_stack *stack_a)
{
	int		len;
	t_stack	*last;
	t_stack	*tmp;
	
	if (!stack_a)
		return (0);
	tmp = stack_a;
	last = stack_a->prev;
	len = 1;
	tmp = tmp->next;
	while (tmp->prev != last)
	{
		len++;
		tmp = tmp->next;
	}
	return (len);
}

void	ft_copy_list_push(t_stack **tmp, t_stack *stack, int len, t_stacks *stacks)
{
	int	pos;

	pos = 1;
	while (len--)
	{
		ft_insert_nbr(stack->nbr, pos++, tmp, len, stacks);
		stack = stack->next;
	}
}