/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 10:48:57 by atucci            #+#    #+#             */
/*   Updated: 2023/10/29 22:46:32 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* 1 means alive :)
	* 0 means death ☠️ */
int	check_table(t_table *table_to_check)
{
	int	result;

	pthread_mutex_lock(&table_to_check->lock_table);
	result = table_to_check->someone_is_dead;
	pthread_mutex_unlock(&table_to_check->lock_table);
	//printf("%s %llu  check the table result: %d%s\n",BLUE, my_get_time() - table_to_check->time_of_start, result, RESET);
	return (result);
}

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
//	printf("%s☠️ function CHECK IF DEAD☠️%s\n", YELLOW, RESET);
	pthread_mutex_lock(&socratis->eat_last_time);
	if (socratis->last_time_eat == 0)
	{
		// edge case if I start checking before a philo has event started to eat;
		usleep(socratis->time_to_die);
		socratis->last_time_eat = 1;
	}
//		printf("%stime[%llu] >= last_eat_time[%zu]%s\n", YELLOW, time, socratis->last_time_eat, RESET);
	if (time >= socratis->last_time_eat && socratis->is_eating == 0)// checking the time to die and if a philos is busy
		{
		pthread_mutex_unlock(&socratis->eat_last_time); // unlock the mutex ?
		//printf("%llu\t", my_get_time() - table->time_of_start);
		//printf("%stime[%llu] >= last_eat_time[%zu]%s\n", RED, time, socratis->last_time_eat, RESET);
		
		pthread_mutex_lock(&table->lock_table);
		table->someone_is_dead = 1;
		// lock the mutex of socratis
		dying(socratis);
		pthread_mutex_unlock(&table->lock_table);
		return ;
		}
	pthread_mutex_unlock(&socratis->eat_last_time);
//		pthread_mutex_unlock(&socratis->state_of_philo);
}

/* helper functon to check if philosopher are full*/
static void	check_if_full(t_table *table, t_plato *plato)
{
//	printf("%s-- function\tCHECK_IF_FULL---%s\n", BG_YELLOW, BG_RESET);
	pthread_mutex_lock(&plato->meals_lock);
		//printf("%sphilo n.%d\t(meal eaten:%d) >= (meals to eat%d)%s\n", BG_YELLOW, plato->name, plato->meal_eaten, table->meals_to_eat, RESET);
		if (plato->meal_eaten >= table->meals_to_eat && plato->philo_is_full == 0)
		{
	//		printf("%sphilo n.%d\t(meal eaten:%d) >= (meals to eat%d)%s\n", BG_YELLOW, plato->name, plato->meal_eaten, table->meals_to_eat, RESET);
	//		printf("%sPhilo n.%dhas eat enough%s\n",BG_YELLOW, plato->name, BG_RESET);
			plato->philo_is_full = 1;
			table->enough_is_enough++;
		}
	pthread_mutex_unlock(&plato->meals_lock);
}
void	*monitoring(void *param)
{
	t_plato	*philos;
	t_table	*table;
	int		count;

	int t = 150;// this value is bogus
	table = (t_table *) param;
	philos = table->array_of_philos;
	count = 0;
	my_usleep(t);
//	printf("MONITOR THREAD HAS STARTED\ntime[%llu]\n", my_get_time());
	// main while cicle, 	if someone is dead 	if the simulation is finished
//		pthread_mutex_lock(&table->lock_table);
	while (!check_table(table) && table->enough_is_enough <= table->array_size) // this condition will be changed in the future
	{
//		pthread_mutex_unlock(&table->lock_table);
		check_for_death(table, &philos[count]);
		if (table->meals_to_eat != 0) // if given amout of meals, check them, otherwise just check for death;
		check_if_full(table, &philos[count]);
		if (table->enough_is_enough >= table->array_size)
			break ;
	if (count < table->array_size - 1)
		count++;
	else
		count = 0;
	if (t <= 1)
		t = 150;
	my_usleep(t--);
	}
//	printf("%sthe monitor thread is finished%s\n", BG_RED, BG_RESET);
	return NULL;
}

