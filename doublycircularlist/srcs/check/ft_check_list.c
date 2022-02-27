/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:02:33 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/22 16:03:29 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
  NAME
  ****
  ft_check_list ---> check list

  SYNOPSIS
  ***********
  #include "push_swap.h"
  int	ft_check_list(t_stack *head_a);

  DESCRIPTION
  ***********
  The function ft_check_list() checks that there is no repeared number in the
  list passed as a parameter.

  At first, create a variable of the same type as the list, which is to be used
  as a copy of the list to compare each number in the list with all the
  remaining numbers in the list, and repeat this process for each number.

  PARAMETERS
  **********
  head_a ---> The head node from the stack a

  RETURN VALUE
  ************
  - One if there is no repeated number in the list
  - Zero if there is repeated numbers
*/

#include "../../incs/push_swap.h"

int	ft_check_list(t_stack *head_a)
{
	t_stack	*temp;

	temp = head_a;
	while (head_a)
	{
		temp = temp->next;
		if (!temp)
			return (1);
		while (temp)
		{
			if (head_a->nbr == temp->nbr)
				return (0);
			temp = temp->next;
		}
		head_a = head_a->next;
		temp = head_a;
	}
	return (1);
}