/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:48:59 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/03 11:18:44 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ra(t_stack **a, int flag)
{
	t_stack	*tmp;
	t_stack	*tr;

	if (*a == NULL || (*a)->next == NULL)
		return ;
	tmp = *a;
	tr = *a;
	*a = (*a)->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = tr;
	tr->next = NULL;
	if (flag == 1)
		ft_printf("ra\n");
}

void	rb(t_stack **b, int flag)
{
	t_stack	*tmp;
	t_stack	*tr;

	if (*b == NULL || (*b)->next == NULL)
		return ;
	tmp = *b;
	tr = *b;
	*b = (*b)->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = tr;
	tr->next = NULL;
	if (flag == 1)
		ft_printf("rb\n");
}

void	rr(t_stack **b, t_stack **a, int flag)
{
	ra(&(*a), 0);
	rb(&(*b), 0);
	if (flag == 1)
		ft_printf("rr\n");
}
