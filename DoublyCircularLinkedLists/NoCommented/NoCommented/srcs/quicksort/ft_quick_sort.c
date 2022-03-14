#include "../../incs/push_swap.h"

/*static void	ft_print_list(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	//printf("direccion = %p nbr = %d prev = %p next = %p\n", stack_a, stack_a->nbr, stack_a->prev, stack_a->next);
	printf("nbr = %d\n", stack_a->nbr);
	stack_a = stack_a->next;
	while (stack_a->prev != tmp->prev)
	{
		//printf("direccion = %p nbr = %d prev = %p next = %p\n", stack_a, stack_a->nbr, stack_a->prev, stack_a->next);
		printf("nbr = %d\n", stack_a->nbr);
		stack_a = stack_a->next;
	}
}*/
/*
static int	ft_partition(t_stack **stack_a, int start, int end)
{
	int	pivot;
	t_stack	*tmp1;
	t_stack	*tmp2;
	t_stack	*tmp3;
	t_stack	*tmp4;
	int		i = start - 1;
	int		j;

	tmp1 = *stack_a;
	j = end;
	while (--j)
		tmp1 = tmp1->next;
	pivot = tmp1->nbr;
	tmp3 = *stack_a;
	//pivot = (*stack_a)->prev->nbr;
	while (tmp3->nbr != pivot)
	{
		tmp1 = *stack_a;
		while (tmp1->nbr != pivot)
			tmp1 = tmp1->next;
		printf("pivot %d\n", tmp1->nbr);
		if (++i < end && tmp3->nbr > pivot)
		{
			printf("i = %d tmp3->nbr = %d stack->nbr = %d\n", i, tmp3->nbr, (*stack_a)->nbr);
			if (i == 1 && tmp3->prev->nbr != pivot)
			{
				i = 0;
				*stack_a = (*stack_a)->next;
			}
			else
			{
				tmp2 = tmp3;
				tmp4 = tmp3;
				tmp3 = tmp3->prev;
				tmp4->prev->next = tmp2->next;
				tmp4->next->prev = tmp2->prev;
				tmp2->prev = tmp1;
				tmp2->next = tmp1->next;
				tmp1->next->prev = tmp2;
				tmp1->next = tmp2;
			}
		}
		tmp3 = tmp3->next;
		printf("\n");
		ft_print_list(*stack_a);
		printf("\n");
	}
	tmp1 = *stack_a;
	i = 1;
	while (tmp1->nbr != pivot)
	{
		i++;
		tmp1 = tmp1->next;
	}
	return (i);
}*//*
static int	ft_partition(t_stack **stack_a, int start, int end)
{
	int	i;
	int	j;
	int nbr;
	t_stack	*pivot_node;
	t_stack	*nbr_node;
	t_stack	*pIndex;

	i = start;
	pIndex  = *stack_a;
	j = end;
	pivot_node = *stack_a;
	nbr_node = *stack_a;
	while (--i)
		pIndex = pIndex->next;
	while (--j)
		pivot_node = pivot_node->next;
	i = start;
	while(i < end)
	{
		if (nbr_node->nbr <= pivot_node->nbr)
		{
			nbr = nbr_node->nbr;
			nbr_node->nbr = pIndex->nbr;
			pIndex->nbr = nbr;
			pIndex = pIndex->next;
		}
		nbr_node = nbr_node->next;
		i++;
	}
	nbr = pIndex->nbr;
	pIndex->nbr = pivot_node->nbr;
	pivot_node->nbr = nbr;
	nbr_node = *stack_a;
	i = 1;
	while (nbr_node->nbr != pivot_node->nbr)
	{
		i++;
		nbr_node = nbr_node->next;
	}
	return (i);
}*/


static int	ft_partition(t_stack **stack_a, int start, int end)
{
	t_stack	*pIndex;
	t_stack	*pNbr;
	t_stack	*nbrtmp;
	int		tmp;
	int		i = start;
	int		j = end;

	//printf("start = %d end = %d\n", start, end);
	nbrtmp = *stack_a;
	pIndex = *stack_a;
	pNbr = *stack_a;
	while (--i)
	{
		pIndex = pIndex->next;
		nbrtmp = nbrtmp->next;
	}
	while(--j)
		pNbr = pNbr->next;
	//printf("%d %d %d\n", pIndex->nbr, nbrtmp->nbr, pNbr->nbr);
	j = end - start + 1;
	while (--j)
	{
		if (nbrtmp->nbr <= pNbr->nbr)
		{
			tmp = nbrtmp->nbr;
			nbrtmp->nbr = pIndex->nbr;
			pIndex->nbr = tmp;
			pIndex = pIndex->next;
		}
		//printf("%d %d %d\n", pIndex->nbr, nbrtmp->nbr, pNbr->nbr);
		nbrtmp = nbrtmp->next;
	}
	tmp = pIndex->nbr;
	pIndex->nbr = pNbr->nbr;
	pNbr->nbr = tmp;
	i = 1;
	nbrtmp = *stack_a;
	while (nbrtmp->nbr != pIndex->nbr)
	{
		nbrtmp = nbrtmp->next;
		i++;
	}
	return (i);
}

int	ft_quick_sort(t_stack **stack_a, int start, int end)
{
	int	pIndex;
	t_stack	*tmp;

	tmp = *stack_a;
	/*ft_print_list(*stack_a);
	pIndex = ft_partition(stack_a, start, end);
	printf("%d\n", pIndex);
	ft_print_list(*stack_a);*/
	if (start < end && ft_check_sorted(tmp))
	{
		//ft_print_list(*stack_a);
		//printf("\n");
		pIndex = ft_partition(&tmp, start, end);
		//ft_print_list(*stack_a);
		//printf("\n");
		//printf("First %d\n", pIndex);
		ft_quick_sort(&tmp, start, pIndex - 1);
		//printf("Second %d\n", pIndex);
		ft_quick_sort(&tmp, pIndex + 1, end);
	}
	if (end % 2 != 0)
		pIndex = (end / 2) + 1;
	pIndex = end / 2;
	//printf("pIndex = %d\n", pIndex);
	while (pIndex--)
		tmp = tmp->next;
	//printf("tmp->nbr = %d\n", tmp->nbr);
	return (tmp->nbr);
}