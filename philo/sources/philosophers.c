/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:46:01 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/18 17:20:12 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
void* philosophers(void *phil) 
{
    t_philo *philo = (t_philo *)phil;
    printf("Philosopher %d is thinking\n", philo->id);
	
    return NULL;
}



int main(int ac, char **av) {
	t_data data;
	int i = 0;
	
    if (ac != 5) {
        printf("Usage: %s number_of_philosophers time_to_die time_to_eat time_to_sleep\n", av[0]);
        return 1;
    }
	if (cheack(&data, av) == false)
	{
		printf("ERROR");
		return (1);
	}
    t_fork forks;
    pthread_mutex_init(&forks.forks, NULL);
    pthread_t philosof[data.number_of_philosophers];
    t_philo *philo = malloc(data.number_of_philosophers * sizeof(t_philo));
    if (philo == NULL) 
	{
        printf("Error: Memory allocation failed\n");
        return 1;
    }
	
	while (i < data.number_of_philosophers)
	{       
		philo[i].id = i + 1;
        pthread_create(&philosof[i], NULL, philosophers, (void *)&philo[i]);
		i++;
	}
	i = 0;
	while ( i < data.number_of_philosophers)
	{
		pthread_join(philosof[i], NULL);
		i++;
	}
	free(philo);
    pthread_mutex_destroy(&forks.forks);
    return 0;
}
