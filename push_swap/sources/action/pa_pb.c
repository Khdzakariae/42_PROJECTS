/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:48:38 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/03 11:18:37 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	pb(t_stack **b, t_stack **a, int flag)
{
	t_stack	*temp;

	if (!(*a))
		return ;
	temp = *a;
	*a = (*a)->next;
	temp->next = *b;
	*b = temp;
	if (flag == 1)
		ft_printf("pb\n");
}

void	pa(t_stack **b, t_stack **a, int flag)
{
	t_stack	*temp;

	if (!*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	temp->next = *a;
	*a = temp;
	if (flag == 1)
		ft_printf("pa\n");
}
