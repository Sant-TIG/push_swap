#include "../incs/push_swap_bonus.h"

void ft_print(char **arg)
{
	int	i;

	i = -1;
	while (arg[++i])
		printf("%s\n", arg[i]);
}

void ft_print_list(t_stack *stack)
{
	t_stack *last;
	t_stack	*tmp;

	tmp = stack;
	last = stack->prev;
	while (tmp != last)
	{
		printf("%d\n", tmp->nbr);
		tmp = tmp->next;
	}
	printf("%d\n", tmp->nbr);
}