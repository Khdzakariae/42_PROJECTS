/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: useraccount <useraccount@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:52:18 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/06 16:57:34 by useraccount      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	handle_exit_error(char **numbers, t_stack **a)
{
	ft_putstr_fd(RED "ERROR\n", 2);
	free_stack(a);
	free(numbers);
	exit(1);
}

void	handle_print_error(t_stack **a, int flag)
{
	if (flag == 1)
	{
		free_stack(a);
		exit(0);
	}
	ft_putstr_fd(RED "ERROR\n", 2);
	free_stack(a);
	exit(1);
}

void	handle_checker_error(t_stack **a, t_stack **b, char *str)
{
	ft_putstr_fd(RED "ERROR\n", 2);
	free_stack(a);
	free_stack(b);
	free(str);
	exit(1);
}
