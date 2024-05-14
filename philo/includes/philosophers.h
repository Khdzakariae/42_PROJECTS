/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:46:33 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/14 11:47:19 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdio.h>
#include <stdbool.h>

# define INT_MAX 2147483647

typedef struct t_list
{
        long number_of_philosophers;
        long time_to_die;
        long time_to_eat;
        long time_to_sleep;
}               t_data;

long	ft_atoi(char *str);


#endif