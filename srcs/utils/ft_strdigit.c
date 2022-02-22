/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdigit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:05:19 by sperez-p          #+#    #+#             */
/*   Updated: 2022/02/22 15:09:21 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

int	ft_strdigit(char *str)
{
	while (ft_isdigit(*str) && *str)
		str++;
	if (!*str)
		return (0);
	return (1);
}
