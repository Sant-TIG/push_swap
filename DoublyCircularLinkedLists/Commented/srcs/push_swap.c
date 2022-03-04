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
  ft_check_args ---> check arguments

  SYNOPSIS
  ***********
  #include "push_swap.h"
  int	ft_check_args(char **args)

  DESCRIPTION
  ***********
  The function ft_check_args() check that all the substrings that make up the two
  dimensional string are made up of digits.
  
  BUILT-IN FUNCTIONS
  ******************
  - ft_digit_str ---> checks if the string pointed to by str is made up of
    digits.

  PARAMETERS
  **********
  args ---> The two-dimensional array in which the arguments are stored.

  RETURN VALUE
  ************
  - One if all substrings are made up with strings
  - Zero if not
*/

static int	ft_check_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i] && ft_digit_str(args[i]))
		i++;
	return (!args[i]);
}

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
    transform each substring into a number and then insert it into the list.
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

static int	ft_treat_args(char **args, t_stack **stack_a)
{
	size_t	pos;

	pos = 1;
	if (!ft_check_args(args))
	{
		write(1, "Error\n", 6);
		return (0);
	}
	/*while (*args)
		ft_insert_nbr()*/
  return (1);

}

static void	ft_print_args(char **args)
{
	int	i;
	i = -1;
	while (args[++i])
		printf("arg[%d] %s\n", i, args[i]);
}


/*
  NAME
  ****
  ft_split ---> split string
  SYNOPSIS
  ***********
  #include "libft.h"
  char	**ft_split(const char *str, char c);
  DESCRIPTION
  ***********
  The function ft_split() divides the string pointed to by str into multiple
  strings delimited by each occurrence of the 'c' character. These strings will
  be stored in a two-dimensional string, which will end with a NULL string.
  
  BUILT-IN FUNCTIONS
  ******************
  - ft_line_counter ---> counts the number of strings to be stored in the two
    dimensional string.
  - ft_process_string ---> iterates through the string and stores in each loop
    the start and end of each substring.
  - ft_fill_substrings ---> fill each substring
  
  PARAMETERS
  **********
  str ---> The string to split.
  c   ---> The delimiting character.
  RETURN VALUE
  ************
  - If the character 'c' is not in str, a two-dimensional string made up of the
    string pointed to by str plus a NULL string. 
  - If the character 'c' is in str, a two-dimensional string made up of the
    substrings plus a NULL string.
  - If str is NULL, return NULL,
*/
int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		argv++;
		if (argc == 2)
		{
			args = ft_split(*argv, ' ');
			ft_print_args(args);
			if (!ft_treat_args(args, &stack_a))
			{

			}
		}
		else
		{
			ft_print_args(argv);
		}
	}
	return (0);
}
