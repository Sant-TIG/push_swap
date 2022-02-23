/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:11:49 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/22 15:14:38 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

/*
  NAME
  ****
  ft_rotate_a ---> rotate stack a
  
  SYNOPSIS
  ***********
  #include "../incs/push_swap.h"
  void	ft_rotate_a(t_stack_a **head_a)
  
  DESCRIPTION
  ***********
  The function ft_reverse_rotate_a() shifts all elements in stack a down one
  position, so that the last element becomes the first.
  
  PARAMETERS
  **********
  head_a ---> The head node from stack a
  head_b ---> The head node from stack b
  
  RETURN VALUE
  ************
  Void function so it returns nothing. The function recieves as parameters the
  memory addresses of the main nodes, so it modifies them directly.
*/

void	ft_rotate_a(t_stack_a **head_a)
{
	t_stack_a	*tmp1;
	t_stack_a	*tmp2;

	tmp1 = *head_a;
	tmp2 = *head_a; //el que no se toca
	tmp1 = tmp1->next;
	*head_a = tmp1;
	tmp2->next = NULL;
	while (tmp1->next != NULL)
		tmp1 = tmp1->next;
	tmp1->next = tmp2;
	printf("ra\n");
}

void	ft_rotate_b(t_stack_b **head_b)
{
	t_stack_b	*tmp1;
	t_stack_b	*tmp2;

	tmp1 = *head_b;
	tmp2 = *head_b; //el que no se toca
	tmp1 = tmp1->next;
	*head_b = tmp1;
	tmp2->next = NULL;
	while (tmp1->next != NULL)
		tmp1 = tmp1->next;
	tmp1->next = tmp2;
	printf("rb\n");
}

void	ft_rotate_ab(t_stack_a **head_a, t_stack_b **head_b)
{
	ft_rotate_a(head_a);
	ft_rotate_b(head_b);
	printf("rr\n");
}
