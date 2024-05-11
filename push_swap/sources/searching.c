/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searching.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:53:19 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/01 17:10:40 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*searching_biggest(t_stack *a)
{
	int		i;
	t_stack	*big;
	t_stack	*tmp;

	i = 0;
	big = a;
	tmp = a;
	while (tmp)
	{
		if (tmp->cont > big->cont)
		{
			big = tmp;
			tmp->index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (big);
}

t_stack	*searching_minimum(t_stack *a)
{
	int		i;
	t_stack	*min;
	t_stack	*tmp;

	i = 0;
	min = a;
	tmp = a;
	while (tmp)
	{
		if (tmp->cont < min->cont)
		{
			min = tmp;
			tmp->index = i;
		}
		tmp = tmp->next;
		i++;
	}
	return (min);
}
