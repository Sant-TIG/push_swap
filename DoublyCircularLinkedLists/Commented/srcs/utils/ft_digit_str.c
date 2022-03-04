/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 16:28:15 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/04 16:33:12 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_digit_str ---> digit string

  SYNOPSIS
  ***********
  #include "push_swap.h"
  int	ft_digit_str(char *str)

  DESCRIPTION
  ***********
  The function ft_digit_str() checks if the string pointed to by str is made up
  of digits.
 
  PARAMETERS
  **********
  str ---> the string to check

  RETURN VALUE
  ************
  - One if the string is made up of digits
  - Zero if not
*/

#include "../../incs/push_swap.h"

int	ft_digit_str(char *str)
{
	while (ft_isdigit(*str) && *str)
		str++;
  return (!*str);
}