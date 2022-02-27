/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:20:44 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/25 14:45:22 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <time.h>

typedef struct s_stack
{
	int	nbr;
	struct s_stack	*prev;
	struct s_stack	*next
}	t_stack;

typedef struct s_pushswap
{
	int	stacka_len;
	int	stackb_len;
	int	pivot_pos;
	int	pivot;
}	t_pushswap;

/* CHECK FUNCTIONS */

/* LINKED LIST FUNCTIONS */

/* MOVEMENTS FUNCTIONS */

/* UTILS FUNCTIONS */

char	**ft_split(const char *s, char c);

#endif