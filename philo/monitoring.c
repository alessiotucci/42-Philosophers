/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:48:57 by atucci            #+#    #+#             */
/*   Updated: 2023/10/17 14:25:20 by atucci           ###   ########.fr       */
/* ************************************************************************** */

#include "philo.h"


static void	dying(t_plato *philo)
{
	console_write(philo->table, philo->name, DIED);
}

/* helper function to check for death*/
static void	check_for_death(t_table *table, t_plato *socratis)
{
	u_int64_t	time;

	time = my_get_time() - socratis->last_time_eat;
	printf("%s☠️ function CHECK IF DEAD☠️%s\n", YELLOW, RESET);
	pthread_mutex_lock(&socratis->state_of_philo);
		if (time >= socratis->time_to_die && !socratis->is_eating)// checking the time to die and if a philos is busy
		{
		printf("%stime[%llu] >=  time_to_die[%zu]%s\n", YELLOW, time, socratis->time_to_die, RESET);
		table->someone_is_dead = 0;
		dying(socratis);
		}
		pthread_mutex_unlock(&socratis->state_of_philo);
}

/* helper functon to check if philosopher are full*/
static void	check_if_full(t_table *table, t_plato *plato)
{
	//printf("%s-- function\tCHECK_IF_FULL---%s\n", BG_YELLOW, BG_RESET);
	pthread_mutex_lock(&plato->meals_lock);
		printf("%sphilo n.%d\t(meal eaten:%d) >= (meals to eat%d)%s\n", BG_YELLOW, plato->name, plato->meal_eaten, table->meals_to_eat, RESET);
		if (plato->meal_eaten >= table->meals_to_eat)
		{
			printf("%sPhilo n.%d\thas eat enough%s\n", BG_YELLOW,plato->name, BG_RESET);
			table->enough_is_enough++;
			//exit(0);
		}
	pthread_mutex_unlock(&plato->meals_lock);
}
void	*monitoring(void *param)
{
	t_plato	*philos;
	t_table	*table;
	int		count;
//u_int64_t	time;

	table = (t_table *) param;
	philos = table->philly;
	count = 0;
	printf("%s------MONITOR THREAD HAS STARTED------%s\n", YELLOW, RESET);
	// main while cicle, 	if someone is dead 	if the simulation is finished
	while (table->someone_is_dead == 0 && table->enough_is_enough <= table->philly_size) // this condition will be changed in the future
	{
		check_for_death(table, &philos[count]);
		check_if_full(table, &philos[count]);
	if (count < table->philly_size - 1)
		count++;
	else
		count = 0;
	my_usleep(999);
	}
	return NULL;
}

