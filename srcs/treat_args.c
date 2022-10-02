#include "../incs/push_swap.h"

static void	ft_check_list(t_stacks  *stacks)
{
	t_stack		*tmp;
	t_stack		*tmp1;
	size_t		len;
	size_t		len1;

	len = stacks->utils->stacka_len;
	tmp = stacks->stack_a;
	while (--len)
	{
		len1 = len;
		tmp1 = tmp->next;
		while (len1--)
		{
			if (tmp->nbr == tmp1->nbr && len > 0)
				ft_error_exit(stacks);
			tmp1 = tmp1->next;
		}
		tmp = tmp->next;
	}
}

static void	ft_check_args(t_stacks *stacks)
{
	size_t	i;
	char	**tmp;

	i = 0;
	tmp = stacks->args;
	while (*(tmp + i) && ft_digit_str(*(tmp + i)))
		i++;
	if (*(tmp + i) != NULL)
		ft_error_exit(stacks);
}

void	ft_treat_args(int argc, char **argv, t_stacks *stacks)
{
	int	i;

	i = -1;
	if (argc == 2)
		stacks->args = ft_split_push(*(argv + 1), ' ', stacks);
	else
		stacks->args = ft_2dstrdup_push(argv + 1, stacks);
	ft_check_args(stacks);
	while (*(stacks->args + ++i))
		ft_insert_end_push(ft_atoi_push(*(stacks->args + i), stacks), &stacks->stack_a, stacks);
	stacks->utils->stacka_len = ft_listlen(stacks->stack_a);
	ft_check_list(stacks);
	ft_check_sorted_a(stacks);
}
