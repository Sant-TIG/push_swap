/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:43:56 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/22 15:09:11 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_strlen ---> string length
  
  SYNOPSIS
  ***********
  #include <string.h>
  size_t(const char *str);
  #include "libft.h"
  int	ft_atoi(const char *str);
  
  DESCRIPTION
  ***********
  The function ft_atoi() mimics the behavior of the atoi() function from
  <stdlib.h> library. Both functions convert the string pointed to by
  str to int. The behaviour is the same as "strtol(str, NULL, 10);" except
  that it detect errors.
  
  PARAMETERS
  **********
  str ---> The string representation of an integral number.
  
  RETURN VALUE
  ************
  This function returns the converted value as an int value. If there is
  an error returns zero.
  
  BUGS
  ****
  errno is not set on error so there is no way to distinguish between 0 as
  an error and as as the converted value. No check for overflow or underflow
  are done. Only base-10 input can be converted.
*/

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
