/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:41:14 by atucci            #+#    #+#             */
/*   Updated: 2023/10/26 14:31:03 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*here I start the thread with their routines.
	* I create a monitor thread that I detach from the rest*/
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
	my_usleep(15);
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
	pthread_detach(the_table->monitor);
}

void	*routing(void *argum)
{
	t_plato	*philosopo;
	t_table	*the_table;

	philosopo = (t_plato *)argum;
	the_table = (t_table *)philosopo->table;
	// Should I create the thread to monitor here?
	if (the_table->philly_size == 1)
	{
	eats(philosopo);
	return (NULL);
	}
		// we need to find a way to make the monitor thread communicated, instead of doing this
	while (!check_table(the_table))// && !philosopo->table->enough_is_enough)
	{
	if (eats(philosopo))
		break; // check this one
	if (sleeps(philosopo))
		break;
	if (thinks(philosopo))
		break;
	}
	return (NULL);
}
