/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:56:26 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/05 18:05:31 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_2numbers_in_stack(t_stack **a)
{
	if ((*a)->cont > (*a)->next->cont)
		sa(&(*a), 1);
	else
		return ;
}

void	sort_3numbers_in_stack(t_stack **a)
{
	t_stack	*big;

	big = searching_biggest(*a);
	if (*a == big)
		ra(&(*a), 1);
	else if ((*a)->next == big)
		rra(&(*a), 1);
	if ((*a)->cont > (*a)->next->cont)
		sa(a, 1);
}

void	sort_5numbers_in_stack(t_stack **a, t_stack **b)
{
	t_stack	*min;
	int		i;
	t_stack	*tmp;

	i = 0;
	while (i < 2)
	{
		tmp = (*a);
		min = searching_minimum(tmp);
		while (*a != min)
		{
			if ((min->index) <= (((tmp)->len / 2)))
				ra(a, 1);
			else if ((min->index) > (((tmp)->len / 2)))
				rra(a, 1);
		}
		pb(b, a, 1);
		i++;
	}
	sort_3numbers_in_stack(a);
	while (*b != NULL)
		pa(b, a, 1);
}

void	push_swap(t_stack **a, t_stack **b, long *tab)
{
	len(*a);
	if ((*a)->len == 2)
		sort_2numbers_in_stack(a);
	else if ((*a)->len == 3)
		sort_3numbers_in_stack(a);
	else if ((*a)->len == 5)
		sort_5numbers_in_stack(a, b);
	else
		sort_numbers(a, b, tab, (*a)->len - 1);
}
