/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:46:01 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/21 19:02:41 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

// void monitoring(t_philo *philo)
// {
//     long curent_time = the_time();
//         if (philo->data->time_to_die > curent_time - philo->time_to_last_eat)
//         {
//             print_msg(3, philo);
//             exit(0);
//         }

    
// }


void *philosophers(t_philo *philo)
{
    while (1)
    {
        long long time =  the_time() - philo->data->start_time;
        thinking(philo);
        pthread_mutex_lock(&philo->first_fork->forks);
        print_msg(0, philo, true);
        pthread_mutex_lock(&philo->second_fork->forks);
        print_msg(0, philo, true);
        print_msg(4, philo, true);	
        ft_usleep(philo->data->time_to_eat);
        pthread_mutex_lock(&philo->time_mutex);
        philo->time_to_last_eat = the_time();
        pthread_mutex_unlock(&philo->time_mutex);
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
    t_fork *forks;
    t_philo *philos;
    if (!cheack(&data, argv)) 
    {
        printf("ERROR\n");
        return 1;
    }
    forks = malloc(data.number_of_philosophers * sizeof(t_fork));
    if (forks == NULL) {
        printf("Error: Memory allocation failed\n");
        return 1;
    }

    philos = malloc(data.number_of_philosophers * sizeof(t_philo));
    if (philos == NULL)
    {
        printf("Error: Memory allocation failed\n");
        free(forks);
        return 1;
    }

    i = 0;
    while (i < data.number_of_philosophers)
    {
        philos[i].id = i ;
        philos[i].data = &data;
        philos[i].time_to_last_eat = 0;
        forks[i].id = i;
        pthread_mutex_init(&forks[i].forks, NULL);
        pthread_mutex_init(&philos[i].time_mutex, NULL);
        if (philos[i].id == 0)
        {
            philos[i].first_fork = &forks[0];
            philos[i].second_fork = &forks[philos->data->number_of_philosophers - 1];
        }
        else if  (philos[i].id % 2)
        {
            philos[i].first_fork = &forks[i - 1];
            philos[i].second_fork = &forks[i];
        }
        else if (philos[i].id % 2 == 0)
        {
            philos[i].first_fork = &forks[i];
            philos[i].second_fork = &forks[i - 1];
        }
        i++;
    }
    start_time(true);
    data.start_time = the_time();
    i = 0;
 	while (i < data.number_of_philosophers)
	{
        pthread_create(&philos[i].thread_philo, NULL, (void *)philosophers, &philos[i]);
		i++;
	}
while (1)
{

    i = 0;
    while (i < data.number_of_philosophers)
    {
        pthread_mutex_lock(&philos[i].time_mutex);
        long current_time = the_time();

        if (philos[i].data->time_to_die <= current_time - philos[i].time_to_last_eat)
        {
            printf("curent time |%ld|\n", current_time);
            pthread_mutex_unlock(&philos[i].time_mutex);
            print_msg(3, &philos[i], false);
            exit(1);
        }
        else
            pthread_mutex_unlock(&philos[i].time_mutex);

        i++;
    }
}
    i = 0;

	 while (i < data.number_of_philosophers)
	 {
        pthread_join(philos[i].thread_philo, NULL);
		i++;
	 }
     
    
	 i = 0;
     
    for (int i = 0; i < data.number_of_philosophers; i++) {
        pthread_mutex_destroy(&forks[i].forks);
    }
    free(forks);
    free(philos);

    return 0;
}
