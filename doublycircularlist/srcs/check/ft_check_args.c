/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:02:05 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/22 16:39:13 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

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

int	ft_check_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i] && ft_digit_str(args[i]))
		i++;
	if (args[i])
			return (0);
	return (1);
}