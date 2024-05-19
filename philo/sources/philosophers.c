/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:46:01 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/19 14:11:53 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"


void* philosophers(void *phil) 
{
    t_philo *philo = (t_philo *)phil;
    t_data *data = philo->data;


    pthread_mutex_lock(&philo->first_fork->forks);
    printf("Fork %d is locked\n", philo->first_fork->id + 1);
    pthread_mutex_lock(&philo->second_fork->forks);
    printf("Fork %d is locked\n", philo->second_fork->id + 1);


    printf("Philosopher %ld is eating\n", philo->id + 1);


    pthread_mutex_unlock(&philo->second_fork->forks);
    printf("Fork %d is unlocked\n", philo->second_fork->id + 1);
    pthread_mutex_unlock(&philo->first_fork->forks);
    printf("Fork %d is unlocked\n", philo->first_fork->id + 1);

    return NULL;
}

int main(int argc, char **argv) 
{ 
    int i = 0; 
    if (argc != 5) {
        printf("Usage: %s number_of_philosophers time_to_die time_to_eat time_to_sleep\n", argv[0]);
        return 1;
    }

    t_data data;
    if (!cheack(&data, argv)) {
        printf("ERROR\n");
        return 1;
    }

    t_fork *forks = malloc(data.number_of_philosophers * sizeof(t_fork));
    if (forks == NULL) {
        printf("Error: Memory allocation failed\n");
        return 1;
    }

    // Initialize forks
 	while (i < data.number_of_philosophers)
	{
        pthread_mutex_init(&forks[i].forks, NULL);
        forks[i].id = i;
		i++;
	}

    pthread_t philosophers_threads[data.number_of_philosophers];
    t_philo philo[data.number_of_philosophers];

    // Assign forks to philosophers
    // while (i < data.number_of_philosophers)
    // {
    //     philo[i].id = i ;
    //     philo[i].data = &data;
    //     if (philo[i].id == 0)
    //     {
    //         philo[i].first_fork = &forks[i];
    //         philo[i].second_fork = &forks[philo->data->number_of_philosophers];
    //     }
    //     else if (philo[i].id % 2 != 0)
    //     {
    //         philo[i].first_fork = &forks[i + 1];
    //         philo[i].second_fork = &forks[i];
    //     }
    //     else if (philo[i].id % 2 == 0)
    //     {
    //         philo[i].first_fork = &forks[i];
    //         philo[i].second_fork = &forks[i + 1];
    //     }
    //     i++;
    // }
    for (int j = 0; j < data.number_of_philosophers; j++) 
    {
        philo[j].id = j ;
        philo[j].data = &data;
        if (philo[j].id == 0)
        {

            philo[j].first_fork = &forks[j];
            philo[j].second_fork = &forks[philo->data->number_of_philosophers] - 1;
        }
        else if  (philo[j].id % 2 != 0)
        {
        
            philo[j].first_fork = &forks[j + 1];
            philo[j].second_fork = &forks[j];
        }
        else if (philo[j].id % 2 == 0)
        {


            philo[j].first_fork = &forks[j];
            philo[j].second_fork = &forks[j + 1];
        }

    }

    // Create philosopher threads
    i = 0;
 	while (i < data.number_of_philosophers)
	{
        pthread_create(&philosophers_threads[i], NULL, philosophers, (void *)&philo[i]);
		i++;
	}

	 i = 0;
	 while (i < data.number_of_philosophers)
	 {
        pthread_join(philosophers_threads[i], NULL);
		i++;
	 }

    // Destroy mutexes and free memory
    for (int i = 0; i < data.number_of_philosophers; i++) {
        pthread_mutex_destroy(&forks[i].forks);
    }
    free(forks);

    return 0;
}
