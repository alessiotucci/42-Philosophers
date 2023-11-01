/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:48:57 by atucci            #+#    #+#             */
/*   Updated: 2023/11/01 15:40:52 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_full(t_table *table_to_check)
{
	int	result;

	pthread_mutex_lock(&table_to_check->lock_table);
	result = table_to_check->someone_is_dead;
	pthread_mutex_unlock(&table_to_check->lock_table);
	return (result);
}

static void	dying(t_plato *philo)
{
	pthread_mutex_lock(&philo->table->lock_table);
	philo->table->someone_is_dead = 1;
	pthread_mutex_unlock(&philo->table->lock_table);
	console_write(philo->table, philo->name, DIED, RED);
	pthread_mutex_lock(&philo->state_of_philo);
	philo->alive = 0;
	pthread_mutex_unlock(&philo->state_of_philo);
}

/* helper function to check for death*/
static void	check_for_death(t_table *table, t_plato *socratis)
{
	u_int64_t	time;

	time = my_get_time();
	pthread_mutex_lock(&socratis->eat_last_time);
	if (socratis->last_time_eat == 0 && socratis->is_eating == 0)
	{
		usleep(10);
		socratis->last_time_eat = 1;
	}
	if (time >= socratis->last_time_eat && socratis->is_eating == 0)
	{
		pthread_mutex_unlock(&socratis->eat_last_time);
		pthread_mutex_lock(&table->lock_table);
		table->someone_is_dead = 1;
		dying(socratis);
		pthread_mutex_unlock(&table->lock_table);
		return ;
	}
	pthread_mutex_unlock(&socratis->eat_last_time);
}

/* helper functon to check if philosopher are full*/
static void	check_if_full(t_table *table, t_plato *plato)
{
	pthread_mutex_lock(&plato->meals_lock);
	if (plato->meal_eaten >= table->meals_to_eat && plato->philo_is_full == 0)
	{
		plato->philo_is_full = 1;
		table->enough_is_enough++;
	}
	pthread_mutex_unlock(&plato->meals_lock);
}

/*monitor function that will be passed to the monitor thread*/
void	*monitoring(void *param)
{
	t_table	*table;
	int		count;
	int		t;

	table = (t_table *) param;
	t = table->time_to_die;
	count = 0;
	my_usleep(t);
	while (!check_table(table) && table->enough_is_enough <= table->array_size)
	{
		check_for_death(table, &table->array_of_philos[count]);
		if (table->meals_to_eat != 0)
			check_if_full(table, &table->array_of_philos[count]);
		if (table->enough_is_enough >= table->array_size)
			break ;
		if (count < table->array_size - 1)
			count++;
		else
			count = 0;
		if (t <= 1)
			t = 50;
		my_usleep(t -= 10);
	}
	return (NULL);
}
