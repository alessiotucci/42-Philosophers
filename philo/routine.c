/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:41:14 by atucci            #+#    #+#             */
/*   Updated: 2023/10/10 15:12:13 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_routine(t_plato *the_array, int how_many)
{
	int count;

	count = 0;
	while (count < how_many)
	{
	pthread_create(&the_array[count].thread, NULL, routing, NULL);
	count++;
	}
	count = 0;
	while (count < how_many)
	{
	pthread_join(the_array[count].thread, NULL);
	count++;
	}
}


void	*routing(void *argum)
{
	if (argum)
		printf("esiste");
	printf("this philospher is eating\n");
	printf("this philospher is sleeping\n");
	printf("this philospher is dieing\n");
	return (NULL);
}
