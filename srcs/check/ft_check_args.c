/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:02:05 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/22 16:39:13 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ft_check_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i] && ft_strdigit(args[i]))
		i++;
	if (args[i])
			return (0);
	return (1);
}
