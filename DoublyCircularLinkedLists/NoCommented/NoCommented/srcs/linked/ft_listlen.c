/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:39:43 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/04 17:45:53 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int	ft_listlen(t_stack *stack_a)
{
	int	nbr;
	int	len;

	if (!stack_a)
		return (0);
	len = 1;
	nbr = stack_a->nbr; 
	while (stack_a->next->nbr != nbr)
	{
		len++;
		stack_a = stack_a->next;
	}
	return (len);
}