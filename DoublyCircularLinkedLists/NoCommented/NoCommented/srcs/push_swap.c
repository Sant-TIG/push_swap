/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperez-p <sperez-p@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/03 14:54:21 by sperez-p          #+#    #+#             */
/*   Updated: 2022/03/03 15:05:19 by sperez-p         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/push_swap.h"

static int	ft_check_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i] && ft_digit_str(args[i]))
		i++;
	return (!args[i]);
}

static int	ft_treat_args(char **args, t_stack **stack_a)
{
	size_t	pos;

	pos = 1;
	if (!ft_check_args(args))
	{
		write(1, "Error1\n", 7);
		return (0);
	}
	//stack_a = NULL;
	while (*args != NULL)
		ft_insert_nbr(ft_atoi(*args++), pos++, stack_a);
  return (1);

}

static void	ft_print_args(char **args)
{
	int	i;
	i = -1;
	while (args[++i])
	{
		printf("arg[%d] %s\n", i, args[i]);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;

	stack_a = NULL;
	stack_b = NULL;
	if (argc > 1)
	{
		argv++;
		if (argc == 2)
		{
			args = ft_split(*argv, ' ');
			ft_print_args(args);
			if (!ft_treat_args(args, &stack_a))
        		return (0);
      		printf("listlen = %zu\n", ft_listlen(stack_a));
		}
		else
		{
			ft_print_args(argv);
      		if (!ft_treat_args(argv, &stack_a))
        		return (0);
		}
	}
	return (0);
}
