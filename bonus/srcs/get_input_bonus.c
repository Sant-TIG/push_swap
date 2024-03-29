#include "../incs/push_swap_bonus.h"

static void	ft_check_a(t_checker *checker)
{
	if (checker->stacka_len > 0)
	{
		if ((int)checker->stackb_len > 0)
		{
			if (ft_dlstcmp(checker->read_utils->str, "pa") != 0)
			{
				if (checker->stackb_len == 0)
						ft_error_exit(checker);
				ft_push_a(&checker->stack_a,&checker->stack_b, &checker);
			}
		}
		if (ft_dlstcmp(checker->read_utils->str, "ra") != 0)
			ft_rotate_a(&checker->stack_a);
		else if (ft_dlstcmp(checker->read_utils->str, "rra") != 0)
			ft_reverse_rotate_a(&checker->stack_a);
		else if (ft_dlstcmp(checker->read_utils->str, "sa") != 0)
			ft_swap_a(&checker->stack_a);
	}
	else if (ft_dlstcmp(checker->read_utils->str, "pa") != 0)
	{
		if (checker->stackb_len == 0)
				ft_error_exit(checker);
			ft_push_a(&checker->stack_a,&checker->stack_b, &checker);
	}
	else
		ft_error_exit(checker);
}

static void	ft_check_b(t_checker *checker)
{
	if (checker->stackb_len > 0)
	{
		if ((int)checker->stacka_len >= 0)
		{
			if (ft_dlstcmp(checker->read_utils->str, "pb") != 0)
			{
				if (checker->stacka_len == 0)
					ft_error_exit(checker);
				ft_push_b(&checker->stack_a, &checker->stack_b, &checker);
			}
		}
		else if (ft_dlstcmp(checker->read_utils->str, "rb") != 0 && checker->stackb_len != 0)
			ft_rotate_b(&checker->stack_b);
		else if (ft_dlstcmp(checker->read_utils->str, "rrb") != 0)
			ft_reverse_rotate_b(&checker->stack_b);
		else if (ft_dlstcmp(checker->read_utils->str, "sb") != 0)
			ft_swap_b(&checker->stack_b);
	}
	else if (ft_dlstcmp(checker->read_utils->str, "pb") != 0)
	{
		if (checker->stacka_len == 0)
			ft_error_exit(checker);
		ft_push_b(&checker->stack_a, &checker->stack_b, &checker);
	}
	else
		ft_error_exit(checker);
}

static void	ft_check_double(t_checker *checker)
{
	if (ft_dlstcmp(checker->read_utils->str, "rr") != 0)
		ft_rotate_ab(&checker->stack_a, &checker->stack_b);
	else if (ft_dlstcmp(checker->read_utils->str, "rrr") != 0)
		ft_reverse_rotate_ab(&checker->stack_a,&checker->stack_b);
	else if (ft_dlstcmp(checker->read_utils->str, "ss") != 0)
		ft_swap_ab(&checker->stack_a, &checker->stack_b);
	else
		ft_error_exit(checker);		

}

static void	ft_check_input(t_checker *checker)
{
	int	c;

	c = checker->read_utils->str->prev->c;
	if (c == 'a')
		ft_check_a(checker);
	else if (c == 'b')
		ft_check_b(checker);
	else if ((c == 'r' || c == 's') && checker->stacka_len > 0 && checker->stackb_len > 0)
		ft_check_double(checker);
	else
		ft_error_exit(checker);
	ft_free_char_dlist(&checker->read_utils->str);
}

void	ft_get_input(t_checker *checker)
{
	size_t	len;

	len = checker->stacka_len;
	while (1)
	{
		read(0, &checker->read_utils->c, 1);
		if (checker->read_utils->c == '\n')
		{
			if (len == checker->stacka_len && ft_check_sorted(checker->stack_a) != 0)
			{
				write(1, "OK\n", 3);
				ft_general_free(checker);
				exit(1);		
			}
			write(1, "KO\n", 3);
			ft_general_free(checker);
			exit(1);
		}
		while (checker->read_utils->c != '\n')
		{
			ft_insert_end_char(checker->read_utils->c, &checker->read_utils->str, checker);
			read(0, &checker->read_utils->c, 1);
		}
		ft_check_input(checker);
	}
}
