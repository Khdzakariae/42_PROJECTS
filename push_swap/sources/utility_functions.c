/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:56:48 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/05 18:05:59 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	add_node(t_stack **head, int data)
{
	t_stack	*tmp;
	t_stack	*temp1;

	tmp = malloc(sizeof(t_stack));
	tmp->cont = data;
	tmp->next = NULL;
	if (*head == NULL)
		*head = tmp;
	else
	{
		temp1 = *head;
		while (temp1->next != NULL)
			temp1 = temp1->next;
		temp1->next = tmp;
	}
}

void	add_element_stack(t_stack **a, int ac, char **av)
{
	char	**numbers;
	int		i;
	int		k;
	long	number;

	k = 0;
	i = 0;
	while (++k <= ac - 1)
	{
		numbers = ft_split(av[k], ' ');
		if (!*numbers)
			handle_exit_error(numbers, a);
		i = 0;
		while (numbers[i] != NULL)
		{
			number = ft_atoi(numbers[i]);
			free(numbers[i]);
			if ((number > INT_MAX) || (number < INT_MIN))
				handle_exit_error(numbers, a);
			add_node(&(*a), number);
			i++;
		}
		free(numbers);
	}
}

long	*convert(t_stack *a)
{
	int		i;
	t_stack	*tmp;
	long	*tab;

	i = 0;
	tmp = a;
	len(a);
	tab = malloc((a->len) * sizeof(long));
	while (tmp)
	{
		tab[i] = tmp->cont;
		tmp = tmp->next;
		i++;
	}
	return (tab);
}

int	sort(long *tab, int len)
{
	int	j;
	int	i;

	while (len != 0)
	{
		i = 0;
		j = i + 1;
		while (j < len)
		{
			if (tab[i] > tab[j])
				ft_swap(&(tab[i]), &(tab[j]));
			i++;
			j++;
		}
		len--;
	}
	return (*tab);
}

void	free_stack(t_stack **stack)
{
	t_stack	*current;
	t_stack	*next;

	if (!(*stack))
		return ;
	current = *stack;
	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
	*stack = NULL;
}
