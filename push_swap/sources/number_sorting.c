/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_sorting.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 09:44:49 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/05 18:04:41 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	part2(t_stack **a, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*big;

	tmp = *b;
	big = searching_biggest(*b);
	while (*b)
	{
		tmp = (*b);
		big = searching_biggest((tmp));
		len(tmp);
		if (*b != big)
		{
			if ((big->index) <= (((tmp)->len / 2)))
				rb(b, 1);
			else if ((big->index) > (((tmp)->len / 2)))
				rrb(b, 1);
		}
		if (*b == big)
			pa(b, a, 1);
	}
}

void	update_indices(int *start, int *end, int lent)
{
	if (*end < lent)
	{
		(*start)++;
		(*end)++;
	}
}

void	determine_end_value(int lent, int *end)
{
	if (lent <= 10)
		*end = 2;
	else if (lent > 10 && lent <= 100)
		*end = 15;
	else if (lent > 100 && lent <= 500)
		*end = 35;
	else
		*end = 40;
}

void	sort_numbers(t_stack **a, t_stack **b, long *tab, int lent)
{
	static int	start;
	int			end;
	t_stack		*tmp;

	determine_end_value(lent, &end);
	tmp = *a;
	while ((tmp))
	{
		if (((tmp)->cont >= tab[start] && (tmp)->cont <= tab[end]))
		{
			pb(b, a, 1);
			update_indices(&start, &end, lent);
		}
		else if ((tmp)->cont < tab[start])
		{
			pb(b, a, 1);
			rb(b, 1);
			if (end < lent)
				update_indices(&start, &end, lent);
		}
		else
			ra(a, 1);
		tmp = *a;
	}
	part2(a, b);
}
