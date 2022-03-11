/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:54:21 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/03 15:05:19 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

/*
  NAME
  ****
  ft_treat_args ---> treat arguments

  SYNOPSIS
  ***********
  included in the main function from push_swap.c
  static int    ft_treat_args(char **args, t_stack **head_a);

  DESCRIPTION
  ***********
  The function ft_treat_args() handles possible errors that may appear when
  entering the arguments.

  - At first it calls the ft_check_args() function to check that all the substrings
    that make up the two dimensional string are made up of digits.
  - If there are all digits, it calls the function ft_insert_nbr() which will
    transform each substring into a number and then insert it into the list. Also
  - Finally, check that the list of numbers is not sorted calling ft_check_sorted()
    function.
  
  BUILT-IN FUNCTIONS
  ******************
  - ft_check_args   ---> checks that each argument is made up of only digits
  - ft_insert_nbr   ---> insert a new node in the list a
  - ft_check_list   ---> check if there is no duplicate number
  - ft_check_sorted ---> check if the list is ordered

  PARAMETERS
  **********
  args   ---> The two-dimensional array in which the arguments are stored.
  head_a ---> The head node from the stack a

  RETURN VALUE
  ************
  - One if there is no problem in any of the checks.
  - Zero if there is a problem.
*/

static int	ft_treat_args(char **args, t_stack **stack_a, t_pushswap *utils)
{
	int	pos;

	pos = 1;
	if (!ft_check_args(args))
	{
		printf("Error1\n");
		return (0);
	}
	while (*args)
		ft_insert_nbr(ft_atoi(*args++), pos++, stack_a);
	utils->stacka_len = ft_listlen(*stack_a);
	if (!ft_check_list(*stack_a, utils))
	{
		printf("Error2\n");
		return (0);
	}
	if (!ft_check_sorted(*stack_a))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_pushswap	utils;
	char	**args;

	stack_a = NULL;
	if (argc > 1)
	{
		argv++;
		if (argc == 2)
		{
			args = ft_split(*argv, ' ');
			if (!ft_treat_args(args, &stack_a, &utils))
				return (0);
			ft_push_swap(&stack_a, &utils);
			ft_print_list(stack_a);
		}
		else
		{
      			if (!ft_treat_args(argv, &stack_a, &utils))
        			return (0);
			ft_push_swap(&stack_a, &utils);
			ft_print_list(stack_a);
		}
	}
	return (0);
}
