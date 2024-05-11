/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss_.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:49:47 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/03 11:18:52 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	ft_swap(long *a, long *b)
{
	long	tmp;

	tmp = 0;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	sa(t_stack **a, int flag)
{
	if (*a != NULL && (*a)->next != NULL)
	{
		ft_swap(&((*a)->cont), &((*a)->next->cont));
	}
	if (flag == 1)
		ft_printf("sa\n");
}

void	sb(t_stack **b, int flag)
{
	if (*b != NULL && (*b)->next != NULL)
	{
		ft_swap(&((*b)->cont), &((*b)->next->cont));
	}
	if (flag == 1)
		ft_printf("sb\n");
}

void	ss(t_stack **a, t_stack **b, int flag)
{
	sa(&(*a), 0);
	sb(&(*b), 0);
	if (flag == 1)
		ft_printf("ss\n");
}
