/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:20:44 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/22 15:24:38 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <time.h>

typedef struct s_stack_a
{
	int					nbr_a;
	struct s_stack_a	*next;
}	t_stack_a;

typedef struct s_stack_b
{
	int					nbr_b;
	struct s_stack_b	*next;
}	t_stack_b;

typedef struct s_pushswap
{
	int		stacka_len;
	int		stackb_len;
	int		mediane_pos;
	int		pivot;
	
}	t_pushswap;

/* CHECK FUNCTIONS */

int	ft_check_args(char **args);
int	ft_check_list(t_stack_a *head_a);
int	ft_check_sorted(t_stack_a *head_a);

/* LINKED LIST FUNCTIONS */

void	ft_insert_nbr_a(int nbr, int pos, t_stack_a **head_a);
void	ft_insert_nbr_b(int nbr, int pos, t_stack_b **head_b);
void	ft_print_list_a(t_stack_a *head_a);
void	ft_print_list_b(t_stack_b *head_b);

/* MOVEMENTS FUNCTIONS */

void	ft_swap_b(t_stack_b **head_b);
void	ft_swap_a(t_stack_a **head_a);
void	ft_swap_ab(t_stack_a **head_a, t_stack_b **head_b);
void	ft_push_a(t_stack_a **head_a, t_stack_b **head_b);
void	ft_push_b(t_stack_a **head_a, t_stack_b **head_b);
void	ft_rotate_a(t_stack_a **head_a);
void	ft_rotate_b(t_stack_b **head_b);
void	ft_rotate_ab(t_stack_a **head_a, t_stack_b **head_b);
void	ft_reverse_rotate_a(t_stack_a **head_a);
void	ft_reverse_rotate_b(t_stack_b **head_b);
void	ft_reverse_rotate_ab(t_stack_a **head_a, t_stack_b **head_b);

/* UTILS FUNCTIONS */

int		ft_atoi(const char *str);
int		ft_isdigit(int c);
size_t	ft_line_counter(const char *s, char c);
char	**ft_split(const char *s, char c);
int		ft_strdigit(char *str);
size_t	ft_strlen(const char *s);

#endif
