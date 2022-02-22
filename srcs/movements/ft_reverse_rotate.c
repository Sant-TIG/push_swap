/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:11:42 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/22 16:41:08 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

void	ft_reverse_rotate_a(t_stack_a **head_a)
{
	t_stack_a	*tmp1;
	t_stack_a	*tmp2;
	t_stack_a	*tmp3;

	tmp1 = *head_a;
	tmp2 = *head_a;
	tmp3 = *head_a;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	while (tmp3->next->next != NULL)
		tmp3 = tmp3->next;
	tmp2->next = tmp1;
	*head_a = tmp2;
	while (tmp2->nbr_a != tmp3->nbr_a)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	printf("rra\n");
}

void	ft_reverse_rotate_b(t_stack_b **head_b)
{
	t_stack_b	*tmp1;
	t_stack_b	*tmp2;
	t_stack_b	*tmp3;

	tmp1 = *head_b;
	tmp2 = *head_b;
	tmp3 = *head_b;
	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	while (tmp3->next->next != NULL)
		tmp3 = tmp3->next;
	tmp2->next = tmp1;
	*head_b = tmp2;
	while (tmp2->nbr_b != tmp3->nbr_b)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	printf("rrb\n");
}

void	ft_reverse_rotate_ab(t_stack_a **head_a, t_stack_b **head_b)
{
	ft_reverse_rotate_a(head_a);
	ft_reverse_rotate_b(head_b);
	printf("rrr\n");
}
