/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:41:14 by atucci            #+#    #+#             */
/*   Updated: 2023/10/22 13:29:46 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_routine(t_table *the_table, int how_many)
{
	int count;
	t_plato *the_array;

	the_table->time_of_start = my_get_time();// this get time is working ?
	the_array = the_table->philly;
	printf("\n-\t--\t\n%s%s---\tstarting of the simulation---%s%s\t\n\n\n\n", YELLOW, BG_RED, BG_RESET, RESET);
	// I was creating the monitor thread here previously
	pthread_create(&the_table->monitor, NULL, monitoring, the_table);
	count = 0;
	while (count < how_many)
	{
	pthread_create(&the_array[count].thread, NULL, routing, &the_array[count]);
	my_usleep(10);
	count++;
	}
	count = 0;
	while (count < how_many)
	{
	pthread_join(the_array[count].thread, NULL);
	//printf("%d has finished their routing\n", the_array[count].name);
	count++;
	}
	// I am not sure if I need to join the monitor thread here or elsewhere
	//pthread_join(the_table->monitor, NULL);
}

void	*routing(void *argum)
{
	t_plato	*philosopo;
	t_table	*the_table;

	philosopo = (t_plato *)argum;
	the_table = (t_table *)philosopo->table;
	// Should I create the thread to monitor here?
	while (!philosopo->table->someone_is_dead && !philosopo->table->enough_is_enough)
	{
	eats(philosopo);
	sleeps(philosopo);
	thinks(philosopo);
	}
	return (NULL);
}
