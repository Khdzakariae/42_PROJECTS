/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:46:01 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/19 10:52:03 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"



void* philosophers(void *phil) 
{
    t_philo *philo = (t_philo *)phil;
    t_data *data = philo->data;

    int left_fork_id = philo->id;
    int right_fork_id = (philo->id + 1) % data->number_of_philosophers;
	

    printf("Philosopher %d is thinking\n", philo->id);

    return NULL;
}

int main(int ac, char **av) 
{
    if (ac != 5) {
        printf("Usage: %s number_of_philosophers time_to_die time_to_eat time_to_sleep\n", av[0]);
        return 1;
    }

    t_data data;
	if (cheack(&data, av) == false)
	{
		printf("ERROR");
		return (1);
	}
    t_fork *forks = malloc(data.number_of_philosophers * sizeof(t_fork));
    if (forks == NULL) 
	{
        printf("Error: Memory allocation failed\n");
        return 1;
    }
	int i = 0 ;
	while (i < data.number_of_philosophers)
	{
        pthread_mutex_init(&forks[i].forks, NULL);
        forks[i].id = i;
		i++;
	}
	
    pthread_t philosophers_threads[data.number_of_philosophers];
    t_philo philo[data.number_of_philosophers];

	i = 0;
	while (i < data.number_of_philosophers)
	{
        philo[i].id = i + 1;
        philo[i].data = &data;
        pthread_create(&philosophers_threads[i], NULL, philosophers, (void *)&philo[i]);
		i++;
	}
	exit(4);
	 i = 0;
	 while (i < data.number_of_philosophers)
	 {
        pthread_join(philosophers_threads[i], NULL);
		i++;
	 }
	 
    for (int i = 0; i < data.number_of_philosophers; i++) {
        pthread_mutex_destroy(&forks[i].forks);
    }
    free(forks);

    return 0;
}
