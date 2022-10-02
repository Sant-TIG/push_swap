#include "../incs/push_swap_bonus.h"

int	ft_isdigit(int c)
{
	return ((c >= 48 && c <= 57) || c == 45);
}

int	ft_digit_str(char *str)
{
	while (ft_isdigit(*str) && *str)
		str++;
	return (!*str);
}

void	ft_check_sorted_a(t_checker *checker)
{
	t_stack	*last;
	t_stack	*tmp;

	last = checker->stack_a->prev;
	tmp = checker->stack_a;
	if (tmp != tmp->next)
	{
		while (tmp->nbr < tmp->next->nbr && tmp != last)
			tmp = tmp->next;
		if (tmp != last)
			return ;
	}
	ft_general_free(checker);
	exit (1);
}



/*int	ft_check_sorted(t_stack *stack)
{
	t_stack	*last;
	t_stack	*tmp;

	last = stack->prev;
	tmp = stack;
	if (tmp != tmp->next)
	{
		while (tmp->nbr < tmp->next->nbr && tmp != last)
			tmp = tmp->next;
		return (stack != last);
	}
	return (0);
}

int	ft_check_sorted2(t_stack *stack)
{
	t_stack	*last;
	t_stack	*tmp;

	last = stack->prev;
	tmp = stack;
	if (tmp != tmp->next)
	{
		while (tmp->nbr > tmp->next->nbr && tmp != last)
			tmp = tmp->next;
		return (stack != last);
	}
	return (0);
}

void	ft_check_sorted_a(t_stacks *stacks)
{
	t_stack	*last;
	t_stack	*tmp;

	last = stacks->stack_a->prev;
	tmp = stacks->stack_a;
	if (tmp != tmp->next)
	{
		while (tmp->nbr < tmp->next->nbr && tmp != last)
			tmp = tmp->next;
		if (tmp != last)
			return ;
	}
	ft_general_free(stacks);
	exit (1);
}
*/