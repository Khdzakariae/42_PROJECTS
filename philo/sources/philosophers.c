/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: useraccount <useraccount@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:46:01 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/20 16:48:38 by useraccount      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void monitoring(t_philo *philo)
{
    if (philo->data->time_to_die < philo->time_to_last_eat)
    {
        print_msg(3, philo);
        exit(0);
    }
}

void *philosophers(t_philo *philo)
{
    while (1)
    {
        monitoring(philo);
        long long time =  the_time() - philo->data->start_time;
        thinking(philo);
        pthread_mutex_lock(&philo->first_fork->forks);
        print_msg(0, philo);
        pthread_mutex_lock(&philo->second_fork->forks);
        print_msg(0, philo);
        print_msg(4, philo);	
        ft_usleep(philo->data->time_to_eat);
        philo->time_to_last_eat = the_time();
        pthread_mutex_unlock(&philo->second_fork->forks);
        pthread_mutex_unlock(&philo->first_fork->forks);
        sleping(philo);
    }
    
    return(NULL);
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
        philo[i].id = i ;
        philo[i].data = &data;

        if (philo[i].id == 0)
        {
            philo[i].first_fork = &forks[0];
            philo[i].second_fork = &forks[philo->data->number_of_philosophers - 1];
        }
        else if  (philo[i].id % 2)
        {
            philo[i].first_fork = &forks[i - 1];
            philo[i].second_fork = &forks[i];
        }
        else if (philo[i].id % 2 == 0)
        {
            philo[i].first_fork = &forks[i];
            philo[i].second_fork = &forks[i - 1];
        }
        i++;
    }
    
    data.start_time = the_time();
    i = 0;
 	while (i < data.number_of_philosophers)
	{
        pthread_create(&philosophers_threads[i], NULL, (void *)philosophers, &philo[i]);
		i++;
	}
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
