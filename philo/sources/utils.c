/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:41:23 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/19 22:14:13 by zel-khad         ###   ########.fr       */
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
		printf("%lld\t%ld has taken a fork \n",time , philo->id);
	else if (flag == 1)
		printf("%lld\t%ld is sleeping \n",time , philo->id);
	else if (flag == 2)
		printf("%lld\t%ld is thinking \n",time , philo->id);
	else if (flag == 3)
		printf("%lld\t%ld died \n",time , philo->id);	
	else if (flag == 4)
		printf("%lld\t%ld is eating \n",time , philo->id);	
		
}

void slepeng_(size_t time)
{
	size_t current_time = the_time();
	while ((the_time() - current_time) < time)
		usleep(500);
}

void sleping(t_philo *philo)
{
	print_msg(1, philo);
	slepeng_(philo->data->time_to_sleep);
}

void thinking(t_philo *philo)
{
	print_msg(2, philo);
}