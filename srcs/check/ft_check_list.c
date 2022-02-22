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

#include "../incs/push_swap.h"

int	ft_check_list(t_stack_a *head_a)
{
	t_stack_a	*temp;

	temp = head_a;
	while (head_a)
	{
		temp = temp->next;
		if (!temp)
			return (1);
		while (temp)
		{
			if (head_a->nbr_a == temp->nbr_a)
				return (0);
			temp = temp->next;
		}
		head_a = head_a->next;
		temp = head_a;
	}
	return (1);
}
