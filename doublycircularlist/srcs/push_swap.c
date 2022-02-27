/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:06:40 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/25 15:25:09 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

/*
  NAME
  ****
  ft_treat_args ---> treat args

  SYNOPSIS
  ***********
  included in the main function from push_swap.c
  static int    ft_treat_args(char **args, t_stack *head_a);

  DESCRIPTION
  ***********
  The function ft_treat_args() handles possible errors that may appear when
  entering the arguments.

  
  The function ft_line_counter() counts the number of strings that result from
  dividing str based on the character c.
  At first, checks if str starts with one or more delimiter characters to ignore
  them. Once this check is done, it loops through str until it reaches the end of 
  str or until it finds other one or more delimiter characters to ignore them again.
  After doing these checks, it makes sure that there is at least one substring, so
  it counts one and repeat the process until str reaches the end.
  
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
  - One if there is no problem in any pf the checks.
  - Zero if there is a problem.
*/



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
static int  ft_treat_args(char **args, t_stack *head_a)
{
    int i;

    i = -1;

}

int main(int argc, char **argv)
{
    t_stack *head_a;
    t_stack *head_b;
    char    **args;

    head_a = NULL;
    head_b = NULL;
    if (argc > 1)
    {
        argv++;
        if (argc == 2)
        {
            args = ft_split(*argv, ' ');
            if (!ft_treat_args(args, &head_a))
                return (0);
            
        }
        else
        {

        }
    }
    return (0);
}