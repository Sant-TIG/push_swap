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
