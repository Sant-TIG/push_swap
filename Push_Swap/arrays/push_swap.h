/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:39:10 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/03 13:39:33 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
   
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

typedef struct s_stack_a
{
	int				nbr_a;
	struct s_stack_a	*next;
}	t_stack_a;

typedef struct s_stack_b
{
	int				nbr_b;
	struct s_stack_b	*next;
}	t_stack_b;

typedef struct s_pushswap
{
	size_t	arg_len;
	
}	t_pushswap;

#endif
