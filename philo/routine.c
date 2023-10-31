/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:41:14 by atucci            #+#    #+#             */
/*   Updated: 2023/10/31 10:03:12 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*here I start the thread with their routines.
	* I create a monitor thread that I detach from the rest*/
void	start_routine(t_table *the_table, int how_many)
{
	int		count;
	t_plato	*the_array;
	bool		flag;

	flag = true;
	the_table->time_of_start = my_get_time();
	the_array = the_table->array_of_philos;
	printf("\n-\t--\t\n%s%s---\tstarting of the simulation---%s%s\t\n\n\n\n", YELLOW, BG_RED, BG_RESET, RESET);
	//pthread_create(&the_table->monitor, NULL, monitoring, the_table);
	count = 0;
	while (count < how_many)
	{
		if (flag == true)
		{
			pthread_create(&the_table->monitor, NULL, monitoring, the_table);
			flag = false;
		}
		pthread_create(&the_array[count].thread, NULL, routing, &the_array[count]);
		my_usleep(1); // start working over there
		count++;
	}
	count = 0;
	while (count < how_many)
	{
		pthread_join(the_array[count].thread, NULL);
		count++;
	}
	pthread_detach(the_table->monitor);
}

void	*routing(void *argum)
{
	t_plato	*philosopo;
	t_table	*the_table;

	philosopo = (t_plato *)argum;
	the_table = (t_table *)philosopo->table;
	if (the_table->array_size == 1)
	{
		eats(philosopo);
		return (NULL);
	}
	while (check_table(the_table) == 0 && the_table->enough_is_enough < the_table->array_size)
	{
		if (eats(philosopo))
			break ;
		if (the_table->enough_is_enough >= the_table->array_size)
			break ;
		if (sleeps(philosopo))
			break ;
		if (the_table->enough_is_enough >= the_table->array_size)
			break ;
		if (thinks(philosopo))
			break ;
		if (the_table->enough_is_enough >= the_table->array_size)
			break ;
	}
	return (NULL);
}
