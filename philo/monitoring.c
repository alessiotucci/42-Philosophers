/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:48:57 by atucci            #+#    #+#             */
/*   Updated: 2023/10/16 12:28:44 by atucci           ###   ########.fr       */
/* ************************************************************************** */

#include "philo.h"


static void	dying(t_plato *philo)
{
	console_write(philo->table, philo->name, DIED);
}

void	*monitoring(void *param)
{
	t_plato	*philos;
	t_table	*table;
	u_int64_t	time;
	int		count;

	table = (t_table *) param;
	philos = table->philly;
	count = 0;
	// check each philospher should be dying? 
	printf("%sthe MONITOR THREAD HAS STARTED%s\n", YELLOW, RESET);
	// main while cicle, 	if someone is dead 	if the simulation is finished
	while (table->someone_is_dead == 0 && table->enough_is_enough == 0) // this condition will be changed in the future
	{
		printf("the time passed after last meal is %llu of philo n.%d\n", my_get_time() - philos[count].last_time_eat, philos[count].name);
		time = my_get_time() - philos[count].last_time_eat;
		//printf("%sINSIDE THE MONITOR THREAD%s\n", RED, RESET);
		// lock before we check
		pthread_mutex_lock(&philos[count].state_of_philo);
		// my_get_time = what?
		if (time >= philos[count].time_to_die && !philos[count].is_eating)// checking the time to die and if a philos is busy
		{
		// someone is dead!!
		table->someone_is_dead = 1;
		dying(&philos[count]);
		exit(0);
	// we need to handle better than an exit()	
		}
		pthread_mutex_unlock(&philos[count].state_of_philo);
	if (count < table->philly_size)
		count++;
	else
		count = 0;
	}
	return NULL;
}

