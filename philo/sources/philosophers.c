/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:46:01 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/14 11:56:06 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int ac, char **av)
{
	t_data	data;

	(void)av;
	if (ac == 5)
	{
		if (cheack(&data, av) == false)
		{
			printf("ERROR");
			return (1);
		}
	}
	else
		printf("%s\n",
			"number_of_philosophers time_to_die time_to_eat time_to_sleep");
	return (0);
}
