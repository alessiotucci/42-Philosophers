/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:41:14 by atucci            #+#    #+#             */
/*   Updated: 2023/10/12 13:20:41 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_routine(t_table *the_table, int how_many)
{
	int count;
	t_plato *the_array;

	the_table->time_of_start = my_get_time();
	the_array = the_table->philly;
	printf("\n\n---starting of the simulation---\n");
	count = 0;
	while (count < how_many)
	{
	pthread_create(&the_array[count].thread, NULL, routing, &the_array[count]);
	count++;
	}
	count = 0;
	while (count < how_many)
	{
	pthread_join(the_array[count].thread, NULL);
	printf("%d has finished their routing\n", the_array[count].name);
	count++;
	}
}


void	*routing(void *argum)
{
	t_plato	*philosopo;

	philosopo = (t_plato *)argum;
	// lock the mutex
	//printf("%d is doing his routine \n", philosopo->name);
	eats(philosopo);
	sleeps(philosopo);
//	thinks(philosopo);
	// unlock the mutex
	return (NULL);
}
