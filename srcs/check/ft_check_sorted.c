/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_sorted.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:03:06 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/22 16:40:01 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
   
#include "../incs/push_swap.h"

int	ft_check_sorted(t_stack_a *head_a)
{
	if (head_a->next != NULL)
	{
		while (head_a->next != NULL && head_a->nbr_a < head_a->next->nbr_a)
			head_a = head_a->next;
		if (head_a->next == NULL)
			return (0);
		return (1);
	}
	return (0);
}
