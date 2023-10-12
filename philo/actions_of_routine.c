/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_of_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:52:01 by atucci            #+#    #+#             */
/*   Updated: 2023/10/12 15:14:17 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void take_forks(t_plato *philo)
{
	pthread_mutex_lock(philo->right_fork);
	console_write(philo->table, philo->name, TAKE_FORK);
	pthread_mutex_lock(philo->left_fork);
	console_write(philo->table, philo->name, TAKE_FORK);
}
/* To start eating we need two forks*/
void	eats(t_plato *philo)
{
	/*pthread_mutex_lock(philo->left_fork);
	console_write(philo->table, philo->name, TAKE_FORK);
	pthread_mutex_lock(philo->right_fork);
	console_write(philo->table, philo->name, TAKE_FORK);*/
	take_forks(philo);
	// perform the action of eating for a certain amount of time
	console_write(philo->table, philo->name, EAT);
	//printf("%llu %d is eating\n", (my_get_time() - philo->table->time_of_start), philo->name);
	my_usleep(philo->time_to_eat);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}


/* We need to think for a certaing amount of time*/ 
void	thinks(t_plato *philo)
{
	console_write(philo->table, philo->name, THINK);
}




/*We need to sleep for a certain amount of time*/
void	sleeps(t_plato *philo)
{
	if (philo)
	{
	console_write(philo->table, philo->name, SLEEP);
	//printf("%llu %d is sleeping\n", (my_get_time() - philo->table->time_of_start), philo->name);
	my_usleep(philo->time_to_sleep);
	}
}
