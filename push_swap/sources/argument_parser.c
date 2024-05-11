/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parser.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:51:53 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/05 18:03:45 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	cheack_sort(t_stack **head)
{
	t_stack	*tmp;

	tmp = (*head);
	while (tmp->next)
	{
		if (!((tmp->cont) < (tmp->next->cont)))
			break ;
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		handle_print_error(head, 1);
	return ;
}

void	cheack_repet(t_stack **head)
{
	t_stack	*tmp;
	t_stack	*tmp1;

	tmp = *head;
	tmp1 = *head;
	while (tmp1->next)
	{
		tmp = tmp1;
		while (tmp->next)
		{
			if ((tmp1->cont) == (tmp->next->cont))
				handle_print_error(head, 0);
			tmp = tmp->next;
		}
		tmp1 = tmp1->next;
	}
	return ;
}

void	len(t_stack *head)
{
	int		temp;
	t_stack	*tmp;

	temp = 0;
	if (!head)
	{
		head->len = 0;
		return ;
	}
	tmp = head;
	while (tmp)
	{
		tmp = tmp->next;
		temp++;
	}
	(head)->len = temp;
}

void	is_top(t_stack *head)
{
	t_stack	*tmp;
	int		middle;
	int		i;

	tmp = head;
	len(head);
	middle = head->len / 2;
	i = 0;
	while (tmp)
	{
		tmp->index = i;
		if (i <= middle)
			tmp->top = 1;
		else if (i > middle)
			tmp->top = 1;
		tmp = tmp->next;
		i++;
	}
}

void	parse_stack(t_stack **a, int flag)
{
	if (flag == 1)
		cheack_sort(a);
	cheack_repet(a);
}
