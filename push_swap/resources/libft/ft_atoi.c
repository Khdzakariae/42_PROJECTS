/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: useraccount <useraccount@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 22:04:37 by zel-khad          #+#    #+#             */
/*   Updated: 2024/04/01 01:37:41 by useraccount      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long	ft_atoi(const char *str)
{
	long	result;
	int	sign;
	int	i;

	result = 0;
	sign = 1;
	i = 0;
	if (!str[i])
		return(55147483647);
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (str[i] == '+')
	{
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if ((result * 10) >= INT_MAX)
			return(55147483647);
		result = result * 10 + (str[i] - '0');
		i++;
	}
	if (str[i] != '\0')
		return(55147483647);
	return (result * sign);
}
