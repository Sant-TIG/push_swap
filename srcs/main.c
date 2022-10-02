#include "../incs/push_swap.h"

static void	ft_control_sort(t_stacks *stacks)
{
	if (stacks->utils->stacka_len == 2)
		ft_rotate_a(&stacks->stack_a);
	else if (stacks->utils->stacka_len == 3)
		ft_treat_three_case(&stacks->stack_a);
	else
		ft_sort_a(stacks, stacks->utils->stacka_len);

}

static void	ft_init_struct(t_stacks *stacks)
{
	stacks->utils = (t_pushswap *)malloc(sizeof(t_pushswap));
	if (!stacks->utils)
		ft_error_exit(stacks);
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->utils->stacka_len = 0;
	stacks->utils->stackb_len = 0;
	stacks->args = NULL;
}

int	main(int argc, char **argv)
{	
	t_stacks	stacks;

	ft_init_struct(&stacks);
	if (argc > 1)
	{
		ft_treat_args(argc, argv, &stacks);
		ft_control_sort(&stacks);
		//ft_print_list(stacks.stack_a);
		//ft_print_list(stacks.stack_b);
		ft_general_free(&stacks);
		return(0);
	}
	ft_general_free(&stacks);
	return (0);
}