/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:11:29 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/22 16:40:32 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

/*
  NAME
  ****
  ft_push_a ---> push node to stack b
  
  SYNOPSIS
  ***********
  #include "../incs/push_swap.h"
  int	ft_push_a(t_stack_a **head_a, t_stack_b **head_b);
  
  DESCRIPTION
  ***********
  The function ft_push_a() takes the first node from stack b and puts it on top
  of stack a. If stack b is empty, does nothing.
  
  PARAMETERS
  **********
  head_a ---> The head node from stack a
  head_b ---> The head node from stack b
  
  RETURN VALUE
  ************
  Void function so it returns nothing. The function recieves as parameters the
  memory addresses of the main nodes, so it modifies them directly.
*/

void	ft_push_a(t_stack_a **head_a, t_stack_b **head_b)
{
	t_stack_b	*tmp;
	t_stack_b	*tmp1;

	tmp = (*head_b)->next;
	tmp1 = *head_b;
	*head_b = tmp;
	ft_insert_nbr_a(tmp1->nbr_b, 1, head_a);
	printf("pa\n");
}

/*
  NAME
  ****
  ft_push_b ---> push node to stack a
  
  SYNOPSIS
  ***********
  #include "../incs/push_swap.h"
  int	ft_push_b(t_stack_a **head_a, t_stack_b **head_b);
  
  DESCRIPTION
  ***********
  The function ft_push_b() takes the first node from stack a and puts it on top
  of stack b. If stack a is empty, does nothing.
  
  PARAMETERS
  **********
  head_a ---> The head node from stack a
  head_b ---> The head node from stack b
  
  RETURN VALUE
  ************
  Void function so it returns nothing. The function recieves as parameters the
  memory addresses of the main nodes, so it modifies them directly.
*/

void	ft_push_b(t_stack_a **head_a, t_stack_b **head_b)
{
	t_stack_a	*tmp;
	t_stack_a	*tmp1;

	tmp = (*head_a)->next;
	tmp1 = *head_a;
	*head_a = tmp;
	ft_insert_nbr_b(tmp1->nbr_a, 1, head_b);
	printf("pb\n");
}
