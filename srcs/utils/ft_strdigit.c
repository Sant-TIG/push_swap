/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:05:19 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/22 15:09:21 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_digit_str---> digit string

  SYNOPSIS
  ***********
  #include "../incs/push_swap.h"
  int	ft_digit_str(char *str);

  DESCRIPTION
  ***********
  The function ft_digit_str() checks if the string pointed to by str is made up
  of digits.

  PARAMETERS
  **********
  str ---> The string to check.

  RETURN VALUE
  ************
  - One if the string is made up of digits.
  - Zero if the string contains any character that is not a digit.
*/

#include "../incs/push_swap.h"

int	ft_digit_str(char *str)
{
	while (ft_isdigit(*str) && *str)
		str++;
	if (!*str)
		return (0);
	return (1);
}
