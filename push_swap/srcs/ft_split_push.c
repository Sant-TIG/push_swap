/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduliz.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/24 13:45:37 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/25 09:08:31 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static char	*ft_splitdup(const char *s, size_t start, size_t finish, t_stacks *stacks)
{
	char	*dest;
	size_t	i;

	i = 0;
	dest = (char *)malloc(sizeof(char) * (finish - start + 1));
	if (!dest)
		ft_error_exit(stacks);
	while (start < finish)
		*(dest + i++) = *(s + start++);
	*(dest + i) = '\0';
	return (dest);
}

static char	**ft_process_string(char **dest, const char *str, char c, t_stacks *stacks)
{
	size_t	i;
	size_t	p1;
	size_t	start;
	size_t	len;

	i = 0;
	p1 = 0;
	start = 0;
	len = ft_strlen(str);
	while (*(str + i))
	{
		while (*(str + i) != c && *(str + i))
		{
			i++;
			if (*(str + i) == c || i == len)
				*(dest + p1++) = ft_splitdup(str, start, i, stacks);
		}
		while (*(str + i) == c && *(str + i))
		{
			i++;
			start = i;
		}
	}
	*(dest + p1) = NULL;
	return (dest);
}

static size_t	ft_line_counter(const char *str, char c)
{
	size_t	count;

	count = 0;
	while (*str == c && *str)
		str++;
	while (*str)
	{
		while (*str && *str != c)
			str++;
		while (*str && *str == c)
			str++;
		count++;
	}
	return (count);
}

char	**ft_split_push(const char *str, char c, t_stacks *stacks)
{
	char	**dest;

	if (!str)
		ft_error_exit(stacks);
	dest = (char **)malloc(sizeof(char *) * (ft_line_counter(str, c) + 1));
	if (!dest)
		ft_error_exit(stacks);
	ft_process_string(dest, str, c, stacks);
	return (dest);
}
