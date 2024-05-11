/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 14:16:55 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/05 18:05:00 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	long	*tab;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		add_element_stack(&a, ac, av);
		parse_stack(&a, 1);
		tab = convert(a);
		sort(tab, a->len);
		push_swap(&a, &b, tab);
		free_stack(&a);
		free(tab);
		tab = NULL;
	}
	else
		exit(1);
}
