/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/20 12:44:19 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/22 15:10:32 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_isdigit ---> is a digit character

  SYNOPSIS
  ***********
  #include <ctype.h>
  int	isdigit(int c);
  #include "libft.h"
  int	ft_isdigit(int c);

  DESCRIPTION
  ***********
  The function ft_isdigit() mimics the behavior of the isdigit() function from
  ctype C library. Both functions check whether c is digit (0 through 9) or not.

  PARAMETERS
  **********
  c ---> The character to be checked.

  RETURN VALUE
  ************
  - Non-zero value if c is a digit.
  - Zero value if not.
*/

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}