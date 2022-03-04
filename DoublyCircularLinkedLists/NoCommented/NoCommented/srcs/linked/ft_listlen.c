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

size_t	ft_listlen(t_stack *start)
{
	size_t	i;
	t_stack	*tmp;

	tmp = start;
	i = 0;
	if (start)
	{
		if (start->next == tmp)
			return (1);
		while (start->next != tmp)
		{
			start = start->next;
			i++;
		}
		return (i);
	}
	return (0);
}
