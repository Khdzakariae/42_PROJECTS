/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: useraccount <useraccount@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:41:23 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/20 14:08:03 by useraccount      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"


long long	the_time(void)
{
	struct timeval	time_;

	gettimeofday(&time_, NULL);
	return (time_.tv_sec * 1000 + time_.tv_usec / 1000);
}

void print_msg(int flag, t_philo *philo)
{
	long long time =  the_time() - philo->data->start_time;

	if (flag == 0)
		printf("%lld\t%ld has taken a fork\n",time , philo->id);
	else if (flag == 1)
		printf("%lld\t%ld is sleeping\n",time , philo->id);
	else if (flag == 2)
		printf("%lld\t%ld is thinking\n",time , philo->id);
	else if (flag == 3)
		printf("%lld\t%ld died\n",time , philo->id);	
	else if (flag == 4)
		printf("%lld\t%ld is eating\n",time , philo->id);	
		
}

void ft_usleep(long time)
{
	long  current_time = the_time();
	while (1)
	{
		if ((the_time() - current_time) >= time)
			break;
		usleep(10);
	}
}

void sleping(t_philo *philo)
{
	print_msg(1, philo);
	ft_usleep(philo->data->time_to_sleep);
}

void thinking(t_philo *philo)
{
	print_msg(2, philo);
}