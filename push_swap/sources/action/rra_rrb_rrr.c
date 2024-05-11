/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:49:22 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/03 11:18:48 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	rra(t_stack **a, int flag)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*a || !(*a)->next)
		return ;
	if (flag == 1)
		ft_printf("rra\n");
	tmp = *a;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *a;
	*a = last;
}

void	rrb(t_stack **b, int flag)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!*b || !(*b)->next)
		return ;
	if (flag == 1)
		ft_printf("rrb\n");
	tmp = *b;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	last = tmp->next;
	tmp->next = NULL;
	last->next = *b;
	*b = last;
}

void	rrr(t_stack **b, t_stack **a, int flag)
{
	if (flag == 1)
		ft_printf("rrr\n");
	rra(&(*a), 0);
	rrb(&(*b), 0);
}
