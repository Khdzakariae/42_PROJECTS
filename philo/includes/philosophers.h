/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: useraccount <useraccount@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:46:33 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/20 09:59:38 by useraccount      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdbool.h>
# include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
# include <sys/time.h>
# include <time.h>
# include <unistd.h>

# define INT_MAX 2147483647

typedef struct s_list
{
	long	number_of_philosophers;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long long  start_time;
}			t_data;


typedef struct s_forks
{
	pthread_mutex_t	forks;
	int				id;	
}	t_fork;

typedef struct s_philo
{
	pthread_t	thread_philo;
	long		id;
	t_data		*data;
	t_fork		*first_fork;
	t_fork		*second_fork;
} t_philo;

void sleping(t_philo *philo);
void thinking(t_philo *philo);
long long	the_time(void);
long		ft_atoi(char *str);
bool		cheack(t_data *data, char **av);
void print_msg(int flag, t_philo *philo);
void ft_usleep(long time);



#endif