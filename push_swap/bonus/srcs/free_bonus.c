# include "../incs/push_swap_bonus.h"

static void	ft_free_2dstr(char **str)
{
	int	i;

	i = -1;
	while (*(str + ++i))
		free(*(str + i));
	free(str);
}

static void	ft_free_char_dlist(t_dlstr *str)
{
	t_dlstr	*tmp;

	tmp = str;
	while (str)
	{
		str = str->next;
		free(tmp);
		tmp = str;
	}
	str = NULL;
}

static void	ft_free_stack_dlist(t_stack *stack)
{
	t_stack *last;
	t_stack	*tmp;

	tmp = stack;
	last = stack->prev;
	while (tmp != last)
	{
		tmp = tmp->next;
		free(stack);
		stack = tmp;
	}
	free(stack);
	stack = NULL;
}

void	ft_general_free(t_checker *checker)
{
	if (checker->read_utils->str)
		ft_free_char_dlist(checker->read_utils->str);
	if (checker->read_utils->tmp_map)
		free(checker->read_utils->tmp_map);
	if (checker->read_utils)
		free(checker->read_utils);
	if (checker->args)
		ft_free_2dstr(checker->args);
	//ft_print_list(checker->stack_a);
	if (checker->stack_a)
		ft_free_stack_dlist(checker->stack_a);
}