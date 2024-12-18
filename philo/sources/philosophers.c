/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: useraccount <useraccount@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:46:01 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/22 17:58:42 by useraccount      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"


int check_arguments(int argc, char **argv, t_data *data) 
{
    if (argc != 5) 
    {
        printf("Usage: %s number_of_philosophers time_to_die time_to_eat time_to_sleep\n", argv[0]);
        return 1;
    }
    if (!cheack(data, argv)) 
    {
        printf("ERROR\n");
        return 1;
    }
    return 0;
}

t_fork* initialize_forks(int number_of_philosophers) 
{
    int i = 0;
    t_fork *forks = malloc(number_of_philosophers * sizeof(t_fork));
    if (forks == NULL) 
    {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    while (i < number_of_philosophers) 
    {
        forks[i].id = i;
        pthread_mutex_init(&forks[i].forks, NULL);
        i++;
    }
    return forks;
}

t_philo* initialize_philosophers(t_data *data, t_fork *forks) 
{
    int i;
    i = 0;
    t_philo *philos = malloc(data->number_of_philosophers * sizeof(t_philo));
    if (philos == NULL) 
    {
        printf("Error: Memory allocation failed\n");
        return NULL;
    }
    pthread_mutex_init(&data->print_mutex, NULL);
    while (i < data->number_of_philosophers) 
    {
        philos[i].id = i;
        philos[i].data = data;
        philos[i].time_to_last_eat = 0;
        philos[i].data->philosopher_died = false;
        pthread_mutex_init(&philos[i].time_mutex, NULL);
        if (i == 0) 
        {
            philos[i].first_fork = &forks[0];
            philos[i].second_fork = &forks[data->number_of_philosophers - 1];
        } 
        else if (i % 2)
        {
            philos[i].first_fork = &forks[i - 1];
            philos[i].second_fork = &forks[i];
        } 
        else 
        {
            philos[i].first_fork = &forks[i];
            philos[i].second_fork = &forks[i - 1];
        }
        i++;
    }
    return philos;
}

bool monitoring(t_philo *philos)
{
    int i = 0;
    while (1) 
    {
        i = 0 ;
        while (i < philos->data->number_of_philosophers)
        {
            pthread_mutex_lock(&philos[i].time_mutex);
            long current_time = the_time();
            if (philos[i].data->time_to_die < current_time - philos[i].time_to_last_eat) 
            {
                philos->data->philosopher_died = true;
                print_msg(3, &philos[i], false);
                // ft_usleep(10, philos->data);
                return(false);
            } 
            
                pthread_mutex_unlock(&philos[i].time_mutex);
        }
        // if (philos->data->philosopher_died)
        //     break;
    }
    return(true);
}

void *philosophers(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    while (!philo->data->philosopher_died)
    {
        thinking(philo);
        pthread_mutex_lock(&philo->first_fork->forks);
        print_msg(0, philo, true);
        pthread_mutex_lock(&philo->second_fork->forks);
        print_msg(0, philo, true);
        print_msg(4, philo, true);	
        ft_usleep(philo->data->time_to_eat, philo->data);
        pthread_mutex_lock(&philo->time_mutex);
        philo->time_to_last_eat = the_time();
        pthread_mutex_unlock(&philo->time_mutex);
        pthread_mutex_unlock(&philo->second_fork->forks);
        pthread_mutex_unlock(&philo->first_fork->forks);
        sleping(philo);
    }
    return NULL;
}


bool start_simulation(t_data *data, t_philo *philos) 
{
    int i = 0;
    start_time(true);
    data->start_time = the_time();

    while (i < data->number_of_philosophers) 
    {
        pthread_create(&philos[i].thread_philo, NULL, philosophers, &philos[i]);
        i++;
    }
    if  (monitoring(philos) == false);
        return(false);
    while (i < data->number_of_philosophers) 
    {
        pthread_join(philos[i].thread_philo, NULL);
        i++;
    }
    return(true);
}



void cleanup(t_fork *forks, t_philo *philos, int number_of_philosophers) 
{
    int i = 0;
    while (i < number_of_philosophers)
    {
        pthread_mutex_destroy(&forks[i].forks);
        i++;
    }
    free(forks);
    free(philos);
}


int main(int argc, char **argv) 
{
    t_data data;
    t_fork *forks;
    t_philo *philos;

    if (check_arguments(argc, argv, &data) != 0) 
        return 1;

    forks = initialize_forks(data.number_of_philosophers);
    if (forks == NULL) 
        return 1;
    philos = initialize_philosophers(&data, forks);
    if (philos == NULL) 
    {
        free(forks);
        return 1;
    }
    if (start_simulation(&data, philos) == false);
    {
        cleanup(forks, philos, data.number_of_philosophers);
        return(1);
    }
    cleanup(forks, philos, data.number_of_philosophers);
    return 0;
}

