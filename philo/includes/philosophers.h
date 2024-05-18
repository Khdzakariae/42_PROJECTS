/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:46:33 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/16 13:42:24 by zel-khad         ###   ########.fr       */
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
}			t_data;


typedef struct s_forks
{
	pthread_mutex_t	forks;
	int				id; // debugging	
}	t_fork;

typedef struct s_philo
{
	pthread_t	thread_philo;
	int	id;
	t_data		*data;
	t_fork		*first_fork;
	t_fork		*second_fork;
} t_philo;

long		ft_atoi(char *str);
bool		cheack(t_data *data, char **av);

#endif