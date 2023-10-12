/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_of_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:52:01 by atucci            #+#    #+#             */
/*   Updated: 2023/10/12 13:51:58 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* To start eating we need two forks*/
void	eats(t_plato *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf("%llu %d has taken a fork\n", (my_get_time() - philo->table->time_of_start), philo->name);
	pthread_mutex_lock(philo->right_fork);
	printf("%llu %d has taken a fork\n", (my_get_time() - philo->table->time_of_start), philo->name);
	// perform the action of eating for a certain amount of time
	printf("%llu %d is eating\n", (my_get_time() - philo->table->time_of_start), philo->name);
	my_usleep(philo->time_to_eat);
	
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}
/* We need to think for a certaing amount of time 
void	thinks(t_plato *philo)
{
	if (philo)
	my_usleep(philo->time_to_think);
}*/
/*We need to sleep for a certain amount of time*/
void	sleeps(t_plato *philo)
{
	if (philo)
	{
	printf("%llu %d is sleeping\n", (my_get_time() - philo->table->time_of_start), philo->name);
	my_usleep(philo->time_to_sleep);
	}
}
