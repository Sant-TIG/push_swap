/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 13:37:36 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/03 13:42:17 by sperez-p         ###   ########.fr       */
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

int	*ft_swap_a(int *nbr)
{
	int	tmp;

	tmp = nbr[0];
	nbr[0] = nbr[1];
	nbr[1] = tmp;
	return (nbr);
}

int	*ft_push_swap(int *nbr)
{
	if (nbr[0] > nbr[1])
		nbr = ft_swap_a(nbr);
	return (nbr);
}

int main(int argc, char **argv)
{
	t_pushswap	utils;
	char		**arg;
	int			j;
	int			*nbr;

	j = -1;
	if (argc > 1)
	{
		if (argc == 2)
		{
			*argv++;
			utils.arg_len = ft_line_counter(*argv, ' ');
			arg = ft_split(*argv, ' ');
			nbr = (int *)malloc(sizeof(int) * utils.arg_len);
			if (!nbr)
				return (0);
			while (*arg)
				nbr[++j] = ft_atoi(*arg++);
			nbr = ft_push_swap(nbr);
			j = -1;
			while (nbr[++j])
				printf("%d\n", nbr[j]);
			return (0);
		}
		else
		{
			nbr = (int *)malloc(sizeof(int) * argc);
			while (*++argv)
				nbr[++j] = ft_atoi(*argv);
			nbr[++j] = '\0';
			j = -1;
			while (nbr[++j])
				printf("%d\n", nbr[j]);
			//ft_push_swap();
			return (0);
		}
	}
	write(1, "Error\n", 6);
	return (0);
}
