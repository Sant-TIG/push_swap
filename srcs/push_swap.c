#include "../incs/push_swap.h"

static int	ft_treat_args(char **args, t_stack **stack_a, t_pushswap *utils)
{
	int	pos;

	pos = 1;
	if (!ft_check_args(args))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	while (*args)
		ft_insert_nbr(ft_atoi(*args++), pos++, stack_a, utils->stacka_len++);
	utils->stacka_len = ft_listlen(*stack_a);
	if (!ft_check_list(*stack_a, utils))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (!ft_check_sorted(*stack_a))
		return (0);

	return (1);
}

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_pushswap	utils;
	char		**args;

	if (argc > 1)
	{
		argv++;
		if (argc == 2)
		{
			args = ft_split(*argv, ' ');
			if (!ft_treat_args(args, &stack_a, &utils))
				return (0);
			ft_control_sort(&stack_a, &utils);
		}
		else
		{
			if (!ft_treat_args(argv, &stack_a, &utils))
				return (0);
			ft_control_sort(&stack_a, &utils);
		}
	}
	return (0);
}


