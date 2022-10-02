#ifndef PUSH_SWAP_BONUS_H

# define PUSH_SWAP_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_stack //doubly circular linked list to store data in stacks
{
	int				nbr;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_dlstr //doubly linked string
{
	char	c;
	struct s_dlstr	*next;
	struct s_dlstr	*prev;
}	t_dlstr;

typedef struct s_read
{
	t_dlstr	*str;
	t_dlstr	*tmp;
	char	c;
	int		fd;
	char	*tmp_map;
}	t_read;

typedef struct s_checker
{
	t_read	*read_utils;
	t_stack	*stack_a;
	t_stack	*stack_b;

	char	**args;

	size_t	stacka_len;
	size_t	stackb_len;
}	t_checker;

/* UTILS FUNCTIONS */

char	**ft_split_checker(const char *str, char c, t_checker *checker);
char	**ft_2dstrdup_checker(char **str, t_checker *checker);
size_t	ft_2dstrlen(char **str);
size_t	ft_strlen(const char *str);
int		ft_digit_str(char *str);
int		ft_isdigit(int c);
int		ft_atoi_checker(const char *str, t_checker *checker);

/* LINKED UTILS FUNCTIONS */

void	ft_insert_end_checker(int nbr, t_stack **stack, t_checker *checker);
int		ft_listlen(t_stack *stack_a);
void	ft_check_sorted_a(t_checker *checker);
void	ft_insert_begin(int nbr, t_stack **stack, t_checker *checker);

/* CHECKER FUNCTIONS */

void	ft_treat_args(int argc, char **argv, t_checker *checker);

/* PRINT FUNCTIONS */

void	ft_print(char **arg);
void	ft_print_list(t_stack *stack);

/* FREE FUNCTIONS */

void	ft_general_free(t_checker *checker);

/* ERROR FUNCTIONS */

void	ft_error_exit(t_checker *checker);

#endif