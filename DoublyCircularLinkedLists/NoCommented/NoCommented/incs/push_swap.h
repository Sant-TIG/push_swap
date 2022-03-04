/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:49:13 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/03 20:47:11 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_stack
{
	int				nbr;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

typedef struct s_pushswap
{
	size_t	stacka_len;
	size_t	stackb_len;
}	t_pushswap;

/* LINKED FUNCTIONS */

size_t	ft_listlen(t_stack *start);
void    ft_insert_nbr(int nbr, int pos, t_stack **stack_a);

/* UTILS FUNCTIONS */

int	ft_atoi(const char *str);
char	**ft_split(const char *str, char c);
size_t	ft_strlen(const char *str);
int	ft_digit_str(char *str);
int	ft_isdigit(int c);

#endif
