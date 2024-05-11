/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 10:08:15 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/05 12:50:32 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	check_sorting(t_stack **head)
{
	t_stack	*tmp;

	tmp = (*head);
	while (tmp->next)
	{
		if (!((tmp->cont) < (tmp->next->cont)))
		{
			ft_printf("KO\n");
			break ;
		}
		tmp = tmp->next;
	}
	if (tmp->next == NULL)
		ft_printf("OK\n");
	return ;
}

void	checker_generate_commands(t_stack **a, t_stack **b, char *str)
{
	if (ft_strcmp(str, "pa\n") == 0)
		pa(b, a, 0);
	else if (ft_strcmp(str, "pb\n") == 0)
		pb(b, a, 0);
	else if (ft_strcmp(str, "ra\n") == 0)
		ra(a, 0);
	else if (ft_strcmp(str, "rb\n") == 0)
		rb(b, 0);
	else if (ft_strcmp(str, "rr\n") == 0)
		rr(b, a, 0);
	else if (ft_strcmp(str, "rra\n") == 0)
		rra(a, 0);
	else if (ft_strcmp(str, "rrb\n") == 0)
		rrb(b, 0);
	else if (ft_strcmp(str, "rrr\n") == 0)
		rrr(b, a, 0);
	else if (ft_strcmp(str, "sa\n") == 0)
		sa(a, 0);
	else if (ft_strcmp(str, "sb\n") == 0)
		sb(b, 0);
	else if (ft_strcmp(str, "ss\n") == 0)
		ss(a, b, 0);
	else
		handle_checker_error(a, b, str);
}

void	checker_program(t_stack **a, t_stack **b)
{
	char	*str;

	str = get_next_line(0);
	while (str)
	{
		checker_generate_commands(a, b, str);
		free(str);
		str = get_next_line(0);
	}
	if ((*b) || !(*a))
	{
		ft_printf("KO\n");
		return ;
	}
	check_sorting(a);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac > 1)
	{
		add_element_stack(&a, ac, av);
		parse_stack(&a, 0);
		checker_program(&a, &b);
		free_stack(&a);
	}
	else
		exit(1);
}
