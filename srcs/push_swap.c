/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:06:40 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/22 16:35:49 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/push_swap.h"

static int	ft_treat_args(char **args, t_stack_a **head_a)
{
	size_t	pos;

	pos = 1;
	if (!ft_check_args(args))
	{
		printf("Error1\n");
		return (0);		
	}
	while (*args)
		ft_insert_nbr_a(ft_atoi(*args++), pos++, head_a);
	if (!ft_check_list(*head_a))
	{
		printf("Error2\n");
		return (0);					
	}
	if (!ft_check_sorted(*head_a))
		return (0);
	return (1);
}
/*
static void	ft_print_args(char **args)
{
	int	i;
	i = -1;
	while (args[++i])
		printf("arg[%d] %s\n", i, args[i]);
}*/

void	ft_get_mediane(t_stack_a *head_a, t_pushswap *utils)
{
	int	i;

	i = 1;
	srand(time(0));
	utils->mediane_pos = (rand() % utils->stacka_len) + 1;
	printf("mediane = %d\n", utils->mediane_pos);
	while (utils->mediane_pos > i)
	{
		head_a = head_a->next;
		i++;
	}
	utils->pivot = head_a->nbr_a;
}

int	ft_listlen(t_stack_a *head_a)
{
	int	i;

	i = 0;
	while (head_a)
	{
		head_a = head_a->next;
		i++;
	}
	return (i);
}

void	ft_push_swap(t_stack_a **head_a, t_stack_b **head_b, t_pushswap *utils)
{
	int	i;

	i = utils->stacka_len;
	utils->stackb_len = 0;
	while (i-- > 0 && utils->stacka_len > 1)
	{
		if ((*head_a)->nbr_a == utils->pivot)
			ft_rotate_a(head_a);
		else
		{
			if ((*head_a)->nbr_a < utils->pivot)
			{
				ft_push_b(head_a, head_b);
				utils->stacka_len--;
				utils->stackb_len++;
			}
			else
				ft_rotate_a(head_a);
		}
		//printf("i = %d\n", i);
	}
}


/*----------------------------------------------------------------*/

/*
int	ft_get_pivot_pos(t_stack_a *head_a, t_pushswap *utils, int start, int end)
{
	int	part_index;
	int	i;
	i = start;
	part_index = start;
	ft_get_mediane(head_a, utils);
	while (i < end)
	{
		if ()
	}
}
*/
void	ft_move_node_right(t_stack_a **head_a, int pos1, int pos2)
{
	/*t_stack_a *prevX = NULL;
	t_stack_a *currX = *head_a;
	t_stack_a *currY = *head_a;
	if (pos1 == 1)
	{
	}
	while (pos1-- > 1)
	{
		prevX = currX;
		currX = currX->next;
	}
	while (pos2--)
		currY = currY->next;
	prevX->next = currX->next;
	currX->next = currY->next;
	currY->next = currX;*/
	while (--pos1 > 1)
		*head_a = (*head_a)->next;
	(*head_a)->next = (*head_a)->next->next;
	while (pos2--)
}

void ft_treat_left(t_stack_a **head_a, t_pushswap *utils, int pos1)
{
	int	pos = pos1;
	int pos2 = 1;
	while (--pos)
	{
		if ((*head_a)->nbr_a > utils->pivot)
			ft_move_node_right(head_a, pos2, pos1);
		*head_a = (*head_a)->next;
		pos2++;
	}
}

void ft_treat_right(t_stack_a **head_a, t_pushswap *utils, int pos1)
{
	int	pos = pos1;
	int pos2 = pos1 + 1;
	int	i;

	i = (utils->stacka_len) - pos1;
	while (i--)
	{
		if ((*head_a)->nbr_a < utils->pivot)
			ft_move_node_left(head_a, pos2, pos1);
		*head_a = (*head_a)->next;
		pos2++;
	}
}

void	ft_get_mediane(t_stack_a *head_a, int end)
{
	int	i;

	i = 1;
	srand(time(0));
	utils->mediane_pos = (rand() % end) + 1;
	printf("mediane = %d\n", utils->mediane_pos);
	while (utils->mediane_pos > i)
	{
		head_a = head_a->next;
		i++;
	}
	utils->pivot = head_a->nbr_a;
}

int ft_get_pivot_pos(t_stack_a **head_a, int *pivot_pos, int start, int end)
{
	ft_get_mediane(head_a, end);
	ft_treat_left(head_a, utils, utils->mediane_pos);
	ft_treat_right(head_a, utils, utils->mediane_pos);
}

void	ft_quick_sort(t_stack_a *head_a, t_pushswap *utils, int start, int end)
{
	int	pivot_pos;

	if (start < end)
	{
		ft_get_pivot_pos(head_a, &pivot_pos, start, end);
		ft_quick_sort(head_a, utils, start, pivot_pos - 1);
		ft_quick_sort(head_a, utils, pivot_pos + 1, end);
	}
}


/*----------------------------------------------------------------*/
/*----------------------------------------------------------------*/


int main(int argc, char **argv)
{
	t_stack_a	*head_a;
	t_stack_b	*head_b;
	t_pushswap	utils;
	char		**args;

	head_a = NULL;
	head_b = NULL;
	if (argc > 1)
	{
		//ft_print_args(argv);
		argv++;
		if (argc == 2)
		{
			//ft_print_args(argv);
			args = ft_split(*argv, ' ');
			//ft_print_args(args);
			if (!ft_treat_args(args, &head_a))
				return (0);
			utils.stacka_len = ft_listlen(head_a);
			printf("stack a length = %d\n", utils.stacka_len);
			//ft_get_pivot(head_a, &utils);
			ft_get_mediane(head_a, &utils);
			printf("pivot = %d\n", utils.pivot);
			//ft_quick_sort(head_a, &utils, 0, utils.stacka_len);
			printf("\nLista A\n");
			ft_print_list_a(head_a);
			printf("\nLista B\n");
			ft_print_list_b(head_b);
			ft_push_swap(&head_a, &head_b, &utils);
			printf("\nLista A\n");
			ft_print_list_a(head_a);
			printf("\nLista B\n");
			ft_print_list_b(head_b);
		}
		else
		{
			//ft_print_args(argv);
			if (!ft_treat_args(argv, &head_a))
				return (0);
			utils.stacka_len = ft_listlen(head_a);
			printf("arg_len = %d\n", utils.stacka_len);
			printf("\nLista A\n");
			ft_print_list_a(head_a);
			printf("\nLista B\n");
			ft_print_list_b(head_b);
		}
	}
	return (0);
}
/*
int main(int argc, char **argv)
{
	t_stack_a	*head_a;
	t_stack_b	*head_b;
	char		**args;
	head_a = NULL;
	head_b = NULL;
	if (argc > 1)
	{
		*argv++;
		if (argc == 2)
		{
			args = ft_split(*argv, ' ');
			if (!ft_treat_args(args, &head_a, &head_b))
				return (0);
		}
		else
			if (!ft_treat_args(args, &head_a, &head_b))
				return (0);
	}
	return (0);
}*/
