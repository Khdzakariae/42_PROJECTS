/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zel-khad <zel-khad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 11:46:01 by zel-khad          #+#    #+#             */
/*   Updated: 2024/05/18 09:53:17 by zel-khad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"
int *cont = 0;
pthread_mutex_t mutex;
void* generete()
{

	int value = (rand() % 6 + 1);
	int *result = malloc(sizeof(int));
	*result = value;
	return(void*) result;
}

int	main(int ac, char **av)
{
	t_data	data;
	pthread_mutex_t mutex;

	if (ac == 5)
	{
		if (cheack(&data, av) == false)
		{
			printf("ERROR");
			return (1);
		}
		else
		{
			pthread_t philosof[data.number_of_philosophers];
			int i = 0;
			pthread_mutex_init(&mutex, NULL);
			while (i < data.number_of_philosophers)
			{
				pthread_create(&philosof[i], NULL, generete ,NULL);
				i++;
			}
		}
	}
	else
		printf("%s\n",
			"number_of_philosophers time_to_die time_to_eat time_to_sleep");
	return (0);
}


// int main ()
// {
// 	int *res = 0;
// 	pthread_t t1;
// 	pthread_create(&t1, NULL, generete, NULL);
// 	// pthread_create(&t2, NULL, generete, NULL);

// 	pthread_join(t1, (void**) &res);
// 	// pthread_join(t2, NULL);

// 	printf("the addres of the res is %d\n", *res);
// 	free(res);
// }