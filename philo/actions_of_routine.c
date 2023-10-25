/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_of_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:52:01 by atucci            #+#    #+#             */
/*   Updated: 2023/10/25 12:32:02 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void take_forks(t_plato *philo, int flag)
{
//	pthread_mutex_lock(&philo->state_of_philo);
//	if (philo->alive == 1)
// do something about it
//	pthread_mutex_unlock(&philo->state_of_philo);

	if (flag == 1)
	{
	console_write(philo->table, philo->name, TAKE_FORK, YELLOW);
	my_usleep(philo->time_to_die);
	return ;
	}
	pthread_mutex_lock(philo->right_fork);
	console_write(philo->table, philo->name, TAKE_FORK, YELLOW);
// do something about it?	
	pthread_mutex_lock(philo->left_fork);
	console_write(philo->table, philo->name, TAKE_FORK, YELLOW);
}
static void	drops_forks(t_plato *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(&philo->state_of_philo);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->state_of_philo);
}
/* To start eating we need two forks*/
void	*eats(t_plato *philo)
{
	/*check the take forks function */
	t_table *table;

	table = philo->table;
	if (table->philly_size == 1)
	{
		(take_forks(philo, 1));
		return NULL;
	}
	else
		take_forks(philo, 0);
	// writing the eating...
	console_write(philo->table, philo->name, EAT, GREEN);
// locking the status, and set the status for eating
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
	drops_forks(philo); // changing the status here!
	return NULL;
}

/* We need to think for a certaing amount of time*/ 
void	thinks(t_plato *philo)
{
	console_write(philo->table, philo->name, THINK, GRAY);
}

/*We need to sleep for a certain amount of time*/
void	sleeps(t_plato *philo)
{
	if (philo)
	{
	console_write(philo->table, philo->name, SLEEP, CYAN);
	//printf("%llu %d is sleeping\n", (my_get_time() - philo->table->time_of_start), philo->name);
	my_usleep(philo->time_to_sleep);
	}
}
