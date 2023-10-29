/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_of_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:52:01 by atucci            #+#    #+#             */
/*   Updated: 2023/10/29 12:27:47 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int take_forks(t_plato *philo, int flag)
{
/*	int d;
	if (philo->name % 2 == 0)
		d = 0;
	else
		d = 5;
*/
	if (flag == 1)
	{
	console_write(philo->table, philo->name, TAKE_FORK, YELLOW);
	my_usleep(philo->time_to_die);
	return 1;
	}
		//printf("%s TAKE FORK!\n %llu  check the table result: %d\tphilo->alive[%d]%s\n", RED, my_get_time() - philo->table->time_of_start, check_table(philo->table), philo->alive, RESET);
	if (check_table(philo->table) == 0 && philo->alive == 1)
	{
		if (check_table(philo->table) || philo->alive == 0)
		return (1);

	pthread_mutex_lock(philo->right_fork);
		if (check_table(philo->table) || philo->alive == 0)
			return (1); // this is the BIG  deal
	console_write(philo->table, philo->name, TAKE_FORK, YELLOW);
// this is the troubles 
	if (check_table(philo->table) || philo->alive == 0)
		return (1);

	pthread_mutex_lock(philo->left_fork);
	console_write(philo->table, philo->name, TAKE_FORK, YELLOW);
	return (0);
	}
	return (1);
}
static int drops_forks(t_plato *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(&philo->state_of_philo);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->state_of_philo);

	//printf("%sdrop forks %d-> check table is [%d]%s\n", BG_RED, philo->name, check_table(philo->table), BG_RESET);
	if (check_table(philo->table) == 1)
		return 1;
	else
		return 0;
}
/* To start eating we need two forks*/
int	eats(t_plato *philo)
{
	/*check the take forks function */
	t_table *table;

	table = philo->table;
	if (table->array_size== 1)
		return ((take_forks(philo, 1)));
	else
	{
		// work here bro
//		printf("%s LET EAT(%d)\n %llu check the table result: %d\tphilo->alive[%d]%s\n", PURPLE, philo->name, my_get_time() - philo->table->time_of_start, check_table(philo->table), philo->alive, RESET);
		if (!check_table(philo->table) && philo->alive == 1)
		{
		if (take_forks(philo, 0))
			return (1);
		console_write(philo->table, philo->name, EAT, GREEN);
		pthread_mutex_lock(&philo->state_of_philo);
		philo->alive = 1;
		philo->is_eating = 1;
		pthread_mutex_unlock(&philo->state_of_philo);
	// perform the action of eating for a certain amount of time
		pthread_mutex_lock(&philo->eat_last_time);
		philo->last_time_eat = my_get_time() + philo->time_to_die;
	//printf("%supdate[%d]%s\nlast time eat is(%llu+%zu)= %zu\n", BG_RED, philo->name, BG_RESET, my_get_time(), philo->time_to_die, philo->last_time_eat);
		pthread_mutex_unlock(&philo->eat_last_time);
	//
		pthread_mutex_lock(&philo->meals_lock);
		philo->meal_eaten++;
		pthread_mutex_unlock(&philo->meals_lock);
	//
		my_usleep(philo->time_to_eat);
		return (drops_forks(philo)); // changing the status here!
		//return (0);
		}
	return (1);
	}
}

/* We need to think for a certaing amount of time*/ 
int	thinks(t_plato *philo)
{
	if (check_table(philo->table) == 0) // condition needed
	{
		console_write(philo->table, philo->name, THINK, GRAY);
		return (0);
	}
	return (1);
}

/*We need to sleep for a certain amount of time*/
int	sleeps(t_plato *philo)
{
	if (check_table(philo->table) == 0)// condition needed
	{
	console_write(philo->table, philo->name, SLEEP, CYAN);
	my_usleep(philo->time_to_sleep);
	return (0);
	}
	return (1);
}
