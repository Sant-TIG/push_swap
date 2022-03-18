#include "../../incs/push_swap.h"

static int	ft_partition(t_stack **stack_a, int start, int end)
{
	t_stack	*pIndex;
	t_stack	*pNbr;
	t_stack	*nbrtmp;
	int		tmp;
	int		i = start;
	int		j = end;

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
	if (start < end && ft_check_sorted(tmp))
	{
		pIndex = ft_partition(&tmp, start, end);
		ft_quick_sort(&tmp, start, pIndex - 1);
		ft_quick_sort(&tmp, pIndex + 1, end);
	}
	if (end % 2 != 0)
		pIndex = (end / 2) + 1;
	pIndex = end / 2;
	while (pIndex--)
		tmp = tmp->next;
	return (tmp->nbr);
}