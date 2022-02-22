/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:31:29 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/03 18:23:22 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"

static size_t	ft_line_counter(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s == c && *s)
		s++;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		while (*s && *s == c)
			s++;
		count++;
	}
	return (count);
}

static char	*ft_splitdup(const char *s, size_t start, size_t finish)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (finish - start + 1));
	if (!dest)
		return (NULL);
	while (start < finish)
		dest[i++] = s[start++];
	dest[i] = '\0';
	return (dest);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	**ft_fill_split(char **dest, const char *s, char c)
{
	size_t	i;
	size_t	p1;
	size_t	start;

	i = 0;
	p1 = 0;
	start = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			i++;
			if (s[i] == c || i == ft_strlen(s))
				dest[p1++] = ft_splitdup(s, start, i);
		}
		while (s[i] == c && s[i])
		{
			i++;
			start = i;
		}
	}
	dest[p1] = NULL;
	return (dest);
}

char	**ft_split(const char *s, char c)
{
	char	**dest;

	if (!s)
		return (NULL);
	dest = (char **)malloc(sizeof(char *) * (ft_line_counter(s, c) + 1));
	if (!dest)
		return (NULL);
	ft_fill_split(dest, s, c);
	return (dest);
}

int	ft_isdigit(int c)
{
	return (c >= 48 && c <= 57);
}


int	ft_atoi(const char *str)
{
	int	result;
	ssize_t	sign;

	result = 0;
	sign = 1;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			sign = -1;
		str++;
	}
	while (ft_isdigit(*str))
		result = (*str++ - 48) + (result * 10);
	return (result * sign);
}

void	ft_insert_nbr(int nbr, int n, t_stack_a **head)
{
	//printf("INSERT NBR\n");
	t_stack_a	*new;
	int		i;

	i = -1;
	new = (t_stack_a *)malloc(sizeof(t_stack_a));
	if (!new)
		return ;
	new->nbr_a = nbr;
	new->next = NULL;
	if (n == 1)
	{
		new->next = *head;
		*head = new;
		return ;
	}
	t_stack_a	*new1;
	new1 = *head;
	while (++i < n - 2)
		new1 = new1->next;
	new->next = new1->next;
	new1->next = new;
}

void	ft_print_linked(t_stack_a *head)
{
	while (head)
	{
		printf("%d\n", head->nbr_a);
		head = head->next;
	}
}

int	ft_get_nbr(t_stack_a *head, size_t pos)
{
	while (head && --pos)
		head = head->next;
	return (head->nbr_a);
}

/*
void	ft_swap(int *a, int *b)
{
	int	temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_swap_a(t_stack_a **head)
{
	t_stack_a	*tmp;

	//tmp = (t_stack_a *)malloc(sizeof(t_stack_a));
	tmp = *head;
	ft_swap(&tmp->nbr_a, &tmp->next->nbr_a);
}
*/

void ft_swap_a(t_stack_a **head)
{
	t_stack_a	*tmp;
	t_stack_a	*second;

	tmp = *head;
	second = (*head)->next
	

}

int main(int argc, char **argv)
{
	t_stack_a 	*head_a;
	t_stack_a	*currx;
	t_stack_a	*curry;
	t_pushswap	utils;
	char		**arg;
	int			j;
	int			i;

	j = -1;
	i = 1;
	head_a = NULL;
	if (argc > 1)
	{
		if (argc == 2)
		{
			utils.arg_len = ft_line_counter(*++argv, ' ');
			arg = ft_split(*argv, ' ');
			while (*arg)
				ft_insert_nbr(ft_atoi(*arg++), i++, &head_a);
			ft_print_linked(head_a);
			ft_push_swap(&head_a);
			ft_print_linked(head_a);
			return (0);
		}
		else
		{
			utils.arg_len = (size_t)argc;
			while (*++argv)
				ft_insert_nbr(ft_atoi(*argv), i++, &head_a);
			ft_print_linked(head_a);
			currx = head_a;
			ft_print_linked(currx);
			curry  = head_a;
			ft_print_linked(curry);

			return (0);
		}
	}
	write(1, "Error\n", 6);
	return (0);
}
