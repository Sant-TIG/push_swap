#include "../incs/push_swap_bonus.h"

static void	ft_insert_empty_char(char c, t_dlstr **str, t_checker *checker)
{
	t_dlstr	*new;

	new = (t_dlstr *)malloc(sizeof(t_dlstr));
	if (!new)
		ft_error_exit(checker);
	new->c = c;
	new->next = NULL;
	new->prev = NULL;
	*str = new;
}

void	ft_insert_end_char(char c, t_dlstr **str, t_checker *checker)
{
	t_dlstr	*tmp;
	t_dlstr	*new;

	tmp = *str;
	if (!*str)
	{
		ft_insert_empty_char(c, str, checker);
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	new = (t_dlstr *)malloc(sizeof(t_dlstr));
	if (!new)
		ft_error_exit(checker);
	new->c = c;
	new->next = NULL;
	new->prev = tmp;
	(*str)->prev = new;
	tmp->next = new;
}

void	ft_push_a(t_stack **stack_a, t_stack **stack_b, t_checker **checker)
{
	t_stack	*tmp;
	int		nbr;

	tmp = *stack_b;
	nbr = tmp->nbr;
	*stack_b = (*stack_b)->next;
	(*stack_b)->prev = tmp->prev;
	tmp->prev->next = (*stack_b);
	free(tmp);
	ft_insert_begin(nbr, stack_a, *checker);
	(*checker)->stacka_len++;
	(*checker)->stackb_len--;
}

void	ft_push_b(t_stack **stack_a, t_stack **stack_b, t_checker **checker)
{
	t_stack	*tmp;
	int		nbr;

	tmp = *stack_a;
	nbr = tmp->nbr;
	*stack_a = (*stack_a)->next;
	(*stack_a)->prev = tmp->prev;
	tmp->prev->next = (*stack_a);
	free(tmp);
	ft_insert_begin(nbr, stack_b, *checker);
	(*checker)->stacka_len--;
	(*checker)->stackb_len++;
}

void	ft_reverse_rotate_a(t_stack **stack_a)
{
	*stack_a = (*stack_a)->prev;
}

void	ft_reverse_rotate_b(t_stack **stack_b)
{
	*stack_b = (*stack_b)->prev;
}

void	ft_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate_a(stack_a);
	ft_reverse_rotate_b(stack_b);
}

void	ft_rotate_a(t_stack **stack_a)
{
	*stack_a = (*stack_a)->next;
}

void	ft_rotate_b(t_stack **stack_b)
{
	*stack_b = (*stack_b)->next;
}

void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_rotate_a(stack_a);
	ft_rotate_b(stack_b);
}
void	ft_print_char_dlst(t_dlstr *str)
{
	t_dlstr *tmp;

	tmp = str;
	while (tmp)
	{
		printf("%c", tmp->c);
		tmp = tmp->next;
	}
	printf("\n");
}
void	ft_swap_a(t_stack **stack_a)
{
	int	tmp;

	tmp = (*stack_a)->nbr;
	(*stack_a)->nbr = (*stack_a)->next->nbr;
	(*stack_a)->next->nbr = tmp;
}

void	ft_swap_b(t_stack **stack_b)
{
	int	tmp;

	tmp = (*stack_b)->nbr;
	(*stack_b)->nbr = (*stack_b)->next->nbr;
	(*stack_b)->next->nbr = tmp;
}

void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap_a(stack_a);
	ft_swap_b(stack_b);
}

int	ft_dlstcmp(t_dlstr *dlstr, char *str)
{
	t_dlstr	*tmp;

	if (!dlstr || !str)
		return (0);
	tmp = dlstr;
	while (tmp && *str)
	{
		//printf("%c y %c\n", tmp->c, *str);
		if (tmp->c != *str)
			return (0);
		tmp = tmp->next;
		str++; 
	}
	if (tmp || *str)
		return (0);
	return (1);
}

void	ft_check_rotate(t_checker *checker)
{
	//ft_print_char_dlst(checker->read_utils->str);
	if (ft_dlstcmp(checker->read_utils->str, "ra") != 0)
		ft_rotate_a(&checker->stack_a);
	else if (ft_dlstcmp(checker->read_utils->str, "rb") != 0)
		ft_rotate_b(&checker->stack_b);
	else if (ft_dlstcmp(checker->read_utils->str, "rr") != 0)
		ft_rotate_ab(&checker->stack_a, &checker->stack_b);
	else if (ft_dlstcmp(checker->read_utils->str, "rra") != 0)
		ft_reverse_rotate_a(&checker->stack_a);
	else if (ft_dlstcmp(checker->read_utils->str, "rrb") != 0)
		ft_reverse_rotate_b(&checker->stack_b);
	else if (ft_dlstcmp(checker->read_utils->str, "rrr") != 0)
		ft_reverse_rotate_ab(&checker->stack_a,&checker->stack_b);
	else
		ft_error_exit(checker);
}

void	ft_check_swap(t_checker *checker)
{
	if (ft_dlstcmp(checker->read_utils->str, "sa") != 0)
		ft_swap_a(&checker->stack_a);
	else if (ft_dlstcmp(checker->read_utils->str, "sb") != 0)
		ft_swap_b(&checker->stack_b);
	else if (ft_dlstcmp(checker->read_utils->str, "sss") != 0)
		ft_swap_ab(&checker->stack_a, &checker->stack_b);
	else
		ft_error_exit(checker);
}

void	ft_check_push(t_checker *checker)
{
	if (ft_dlstcmp(checker->read_utils->str, "pa") != 0)
	{
		if (checker->stackb_len == 0)
			ft_error_exit(checker);
		ft_push_a(&checker->stack_a,&checker->stack_b, &checker);
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

int	ft_check_sorted(t_stack *stack_a)
{
	t_stack	*last;
	t_stack	*tmp;

	last = stack_a->prev;
	tmp = stack_a;
	if (tmp != tmp->next)
	{
		while (tmp->nbr < tmp->next->nbr && tmp != last)
			tmp = tmp->next;
		if (tmp != last)
			return (0);
	}
	return (1);
}

void	ft_check_input(t_checker *checker, size_t len)
{
	//printf("char %c\n", checker->read_utils->str->c);
	if (checker->read_utils->str->c == 'r')
		ft_check_rotate(checker);
	else if (checker->read_utils->str->c == 's')
		ft_check_swap(checker);	
	else if (checker->read_utils->str->c == 'p')
		ft_check_push(checker);
	else
		ft_error_exit(checker);
}

void	ft_free_char_dlst(t_dlstr **dlstr)
{
	t_dlstr	*tmp;

	tmp = *dlstr;
	while (tmp)
	{
		tmp = tmp->next;
		free(*dlstr);
		*dlstr = tmp;
	}
	*dlstr = NULL;
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
			//printf("sorting\n");
			//ft_print_list(checker->stack_a);
			if (ft_check_sorted(checker->stack_a) == 0)
			{
				write(1, "KO\n", 3);
				ft_general_free(checker);
				exit(1);
			}
			write(1, "OK\n", 3);
			ft_general_free(checker);
			exit(1);
		}
		while (checker->read_utils->c != '\n')
		{
			ft_insert_end_char(checker->read_utils->c, &checker->read_utils->str, checker);
			read(0, &checker->read_utils->c, 1);
		}
		ft_check_input(checker, len);
		//ft_print_list(checker->stack_a);
		//ft_print_char_dlst(checker->read_utils->str);
		ft_free_char_dlst(&checker->read_utils->str);
	}
}

void	ft_init_checker(t_checker *checker)
{
	checker->read_utils = (t_read *)malloc(sizeof(t_read));
	if (!checker->read_utils)
		ft_error_exit(checker);
	checker->read_utils->str = NULL;
	checker->read_utils->tmp = NULL;
	checker->read_utils->tmp_map = NULL;
	checker->stack_a = NULL;
	checker->stack_b = NULL;
	checker->args = NULL;
	checker->stacka_len = 0;
	checker->stackb_len = 0;
}

int	main(int argc, char **argv)
{
	t_checker	checker;

	ft_init_checker(&checker);
	if (argc > 1)
	{
		ft_treat_args(argc, argv, &checker);
		ft_get_input(&checker);
		ft_print(checker.args);
		ft_print_list(checker.stack_a);
		ft_general_free(&checker);
		return (0);
	}
	write(1, "Error\n", 6);
	ft_general_free(&checker);
	return (0);
}