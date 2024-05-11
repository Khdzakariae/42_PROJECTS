/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 22:04:37 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/02 17:09:54 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	generating_number(char **str, long *result)
{
	while (*(*str) && ft_isdigit(*(*str)))
	{
		if ((*result * 10) >= INT_MAX)
			return ((void)(*result = 55147483647));
		*result = *result * 10 + (*(*str) - '0');
		(*str)++;
	}
}

long	ft_atoi(char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (!str[i])
		return (55147483647);
	else if (((str[i] == '-' || str[i] == '+') && str[i + 1] == '\0'))
		return (55147483647);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	str += i;
	generating_number(&str, &result);
	if (*str)
		return (55147483647);
	return (result * sign);
}
