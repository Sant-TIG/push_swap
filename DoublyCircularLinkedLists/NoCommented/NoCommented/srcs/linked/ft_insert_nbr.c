/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 17:29:05 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/04 19:50:03 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../../incs/push_swap.h"

void	ft_insert_begin(t_stack **stack_a, t_stack **new, t_stack **last)
{
	(*new)->prev = *last;
	(*new)->next = *stack_a;
	(*last)->next = *new;
	(*stack_a)->prev = *new;
	*stack_a = *new;
}

static void    ft_insert_empty(t_stack **stack_a, t_stack **new)
{
	(*new)->prev = *new;
	(*new)->next = *new;
	*stack_a = *new;
}

void    ft_insert_nbr(int nbr, int pos, t_stack **stack_a)
{
	int  i;
	t_stack *new;
	t_stack *last;
	t_stack *tmp;

	i = -1;
	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->nbr = nbr;
	/*Si la lista esta vacia, creamos una lista con un solo elemento*/
	if (!*stack_a)
	{
		ft_insert_empty(stack_a, &new);
	    //new->prev = new;
	    //new->next = new;
	    //(*stack_a) = new;
	    return ;
	}
	tmp = *stack_a;
    last = (*stack_a)->prev;
    if (pos == 1)
    {
		//ft_insert_begin(stack_a, &new, &last);
        /*new->prev = last;
        new->next = *stack_a;
        last->next = new;
        (*stack_a)->prev = new;
        *stack_a = new;*/
        return ;
	}
	while (++i < pos - 1)
		tmp = tmp->next;
	new->prev = tmp->prev;
	new->next = tmp;
	tmp->prev = new;
	tmp->prev->next = new;
}
