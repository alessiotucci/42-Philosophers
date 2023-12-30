/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:41:14 by atucci            #+#    #+#             */
/*   Updated: 2023/11/01 15:44:25 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* We need to think for a certaing amount of time*/
static int	thinks(t_plato *philo)
{
	if (check_table(philo->table) == 0)
	{
		console_write(philo->table, philo->name, THINK, GRAY);
		return (0);
	}
	return (1);
}

/*We need to sleep for a certain amount of time*/
static int	sleeps(t_plato *philo)
{
	if (check_table(philo->table) == 0)
	{
		console_write(philo->table, philo->name, SLEEP, CYAN);
		my_usleep(philo->time_to_sleep);
		return (0);
	}
	return (1);
}

/*here I start the thread with their routines.
	* I create a monitor thread that I detach from the rest*/
void	start_routine(t_table *the_table, int how_many)
{
	bool		flag;
	int			count;
	t_plato		*the_array;

	flag = true;
	the_table->time_of_start = my_get_time();
	the_array = the_table->array_of_philos;
	count = 0;
	while (count < how_many)
	{
		if (flag == true)
		{
			pthread_create(&the_table->monitor, NULL, monitoring, the_table);
			flag = false;
		}
		pthread_create(&the_array[count].thread, NULL,
			routing, &the_array[count]);
		my_usleep(1);
		count++;
	}
	count = 0;
	while (count < how_many)
		pthread_join(the_array[count++].thread, NULL);
	pthread_detach(the_table->monitor);
}

void	*routing(void *argum)
{
	t_plato	*philo;

	philo = (t_plato *)argum;
	if (philo->table->array_size == 1)
	{
		eats(philo);
		return (NULL);
	}
	while (!check_table(philo->table)
		&& philo->table->enough_is_enough < philo->table->array_size)
	{
		if (eats(philo))
			break ;
		if (philo->table->enough_is_enough >= philo->table->array_size)
			break ;
		if (sleeps(philo))
			break ;
		if (philo->table->enough_is_enough >= philo->table->array_size)
			break ;
		if (thinks(philo))
			break ;
		if (philo->table->enough_is_enough >= philo->table->array_size)
			break ;
	}
	return (NULL);
}
