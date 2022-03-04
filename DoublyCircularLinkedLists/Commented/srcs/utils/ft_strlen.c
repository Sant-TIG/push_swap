/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:43:56 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/03 20:47:01 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_strlen ---> string length
  SYNOPSIS
  ***********
  #include <string.h>
  size_t	strlen(const char *s);
  #include "libft.h"
  size_t	ft_strlen(const char *str);
  DESCRIPTION
  ***********
  The function ft_strlen() mimics the behavior of the strlen() function from
  <string.h> C library. Both functions calculate the length of the string pointed
  to by str, excluding the terminating null byte.
  PARAMETERS
  **********
  str ---> The string whose length is to be found.
  RETURN VALUE
  ************
  This function returns the number of bytes in the string pointed to by str.
*/

#include "../../incs/push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
