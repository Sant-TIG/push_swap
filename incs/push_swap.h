#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

# define MALLOC_ERROR 1

/* STACKS DOUBLY CIRCULAR LINKED LIST */

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

/* PUSH SWAP UTILS STRUCTURE */

typedef struct s_pushswap
{
	int	stacka_len;
	int	stackb_len;
}	t_pushswap;

/* MAIN STRUCTURE */

typedef struct s_stacks
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_stack		*pivot_index;
	t_stack		*pivot_nbr;
	t_stack		*nbrtmp;
	t_pushswap	*utils;
	char		**args;
}	t_stacks;

/* PUSH_SWAP FUNCTIONS */

void	ft_treat_args(int argc, char **argv, t_stacks *stacks);
int		ft_check_sorted(t_stack *stack);
int	ft_check_sorted2(t_stack *stack);
void	ft_check_sorted_a(t_stacks *stacks);
void	ft_rotate_a(t_stack **stack_a);
void	ft_rotate_b(t_stack **stack_b);
void	ft_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_swap_a(t_stack **stack_a);
void	ft_swap_b(t_stack **stack_b);
void	ft_swap_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_reverse_rotate_a(t_stack **stack_a);
void	ft_reverse_rotate_b(t_stack **stack_b);
void	ft_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_a(t_stacks *stacks, int len);


/* UTILS FUNCTIONS */

int		ft_digit_str(char *str);
int		ft_isdigit(int c);
int		ft_atoi_push(const char *str, t_stacks *stacks);
char	**ft_split_push(const char *str, char c, t_stacks *stacks);
char	**ft_2dstrdup_push(char **str, t_stacks *stacks);
size_t	ft_2dstrlen(char **str);
size_t	ft_strlen(const char *str);

/* LINKED FUCNTIONS */

void	ft_insert_end_push(int nbr, t_stack **stack, t_stacks *stacks);
void	ft_copy_list_push(t_stack **tmp, t_stack *stack, int len, t_stacks *stacks);
void	ft_insert_empty_push(int nbr, t_stack **stack, t_stacks *stacks);
void	ft_insert_nbr(int nbr, int pos, t_stack **stack, int stack_len, t_stacks *stacks);


/* FREE FUNCTIONS */

void	ft_free_list(t_stack **stack, int len);
void	ft_general_free(t_stacks *stacks);
void	ft_free_dclist(t_stack *stack);

/* EXIT FUNCTIONS */

void	ft_error_exit(t_stacks *stacks);

/* PRINT FUNCTIONS */

void	ft_print(char **arg);
void	ft_print_list(t_stack *stack);


/* AÑADIDAS */

void	ft_check_sorted_b(t_stacks *stacks, t_stack *stack_b);
void	ft_insert_begin(int nbr, t_stack **stack, t_stacks *stacks);
void	ft_push_a(t_stack **stack_a, t_stack **stack_b, t_pushswap **utils, t_stacks *stacks);
void	ft_push_b(t_stack **stack_a, t_stack **stack_b, t_pushswap **utils, t_stacks *stacks);

/*-------------------------------------------------------------------------------------------------------------------*/
/* MOVEMENTS FUNCTIONS */

//void	ft_push_a(t_stack **stack_a, t_stack **stack_b, t_pushswap **utils);
//void	ft_push_b(t_stack **stack_a, t_stack **stack_b, t_pushswap **utils);

void	ft_reverse_rotate_a(t_stack **stack_a);
void	ft_reverse_rotate_b(t_stack **stack_b);
void	ft_reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b);


/* LINKED FUNCTIONS */

//void	ft_free_list(t_stack **stack, int len);
int		ft_quick_sort(t_stack **stack_a, int start, int end, t_stacks *stacks);
int		ft_listlen(t_stack *stack_a);
//void	ft_insert_begin(int nbr, t_stack **stack);
//void	ft_insert_empty(int nbr, t_stack **stack);
//void	ft_insert_end(int nbr, t_stack **stack);

/* PRINT FUNCTIONS */

//void	ft_print_args(char **args);
//void	ft_print_list(t_stack *stack_a);

/* SORT FUNCTIONS */

//void	ft_control_sort(t_stacks *stacks);
//void	ft_sort_a(t_stacks *stacks, int len);
void	ft_sort_b(t_stacks *stacks, int len);
void	ft_treat_three_case(t_stack **stack_a);

#endif
