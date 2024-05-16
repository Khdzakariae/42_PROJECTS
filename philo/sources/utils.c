/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:41:23 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/15 18:41:40 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

long long	the_time(void)
{
	struct timeval	time_;

	gettimeofday(&time_, NULL);
	return (time_.tv_sec * 1000LL + time_.tv_usec / 1000);
}

bool	timing(void)
{
	static clock_t	start_time;
	clock_t			current_time;

	current_time = the_time();
	if (start_time == 0)
		return (start_time = current_time, true);
	else if ((current_time - start_time) <= 400)
		return (false);
	start_time = 0;
	return (true);
}