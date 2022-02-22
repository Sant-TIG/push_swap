/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:11:56 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/22 16:41:15 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_swap_b(t_stack_b **head_b)
{
	t_stack_b	*tmp1;
	t_stack_b	*tmp2;
	t_stack_b	*tmp3;

	tmp1 = *head_b;
	tmp2 = *head_b; //el que no se toca
	tmp1 = tmp1->next;
	*head_b = tmp1;
	tmp3 = tmp1->next;
	tmp1->next = tmp2;
	tmp2->next = tmp3;
	printf("sb\n");
}

void	ft_swap_a(t_stack_a **head_a)
{
	t_stack_a	*tmp1;
	t_stack_a	*tmp2;
	t_stack_a	*tmp3;

	tmp1 = *head_a;
	tmp2 = *head_a; //el que no se toca
	tmp1 = tmp1->next;
	*head_a = tmp1;
	tmp3 = tmp1->next;
	tmp1->next = tmp2;
	tmp2->next = tmp3;
	printf("sa\n");
}

void	ft_swap_ab(t_stack_a **head_a, t_stack_b **head_b)
{
	ft_swap_a(head_a);
	ft_swap_b(head_b);
	printf("ss\n");
}
