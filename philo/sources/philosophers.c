/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:46:01 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/14 13:34:27 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac == 5)
	{
		if (cheack(&data, av) == false)
		{
			printf("ERROR");
			return (1);
		}
		else
		{
			
			printf("number_of_philosophers is |%ld|\n", data.number_of_philosophers);
			printf("time_to_die is |%ld|\n", data.time_to_die);
			printf("time_to_eat is |%ld|\n", data.time_to_eat);
			printf("time_to_sleep is |%ld|\n", data.time_to_sleep);			
		}
	}
	else
		printf("%s\n",
			"number_of_philosophers time_to_die time_to_eat time_to_sleep");
	return (0);
}
