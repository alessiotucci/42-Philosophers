/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_of_routine.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:52:01 by atucci            #+#    #+#             */
/*   Updated: 2023/11/01 14:55:39 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	take_forks(t_plato *philo, int flag)
{
	if (flag == 1)
	{
		console_write(philo->table, philo->name, TAKE_FORK, YELLOW);
		my_usleep(philo->time_to_die);
		return (1);
	}
	if (check_table(philo->table) == 0
		&& philo->alive == 1)
	{
		if (check_table(philo->table) || philo->alive == 0)
			return (1);
		pthread_mutex_lock(philo->right_fork);
		if (check_table(philo->table) || philo->alive == 0)
			return (1);
		console_write(philo->table, philo->name, TAKE_FORK, YELLOW);
		if (check_table(philo->table) || philo->alive == 0)
			return (1);
		pthread_mutex_lock(philo->left_fork);
		if (check_table(philo->table) || philo->alive == 0)
			return (1);
		console_write(philo->table, philo->name, TAKE_FORK, YELLOW);
		return (0);
	}
	return (1);
}

/*drop forks means unlock the mutexes*/
static int	drops_forks(t_plato *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_lock(&philo->state_of_philo);
	philo->is_eating = 0;
	pthread_mutex_unlock(&philo->state_of_philo);
	if (check_table(philo->table) == 1)
		return (1);
	else
		return (0);
}

static void	update_time_meals(t_plato *philo)
{
	pthread_mutex_lock(&philo->eat_last_time);
	philo->last_time_eat = my_get_time() + philo->time_to_die;
	pthread_mutex_unlock(&philo->eat_last_time);
	pthread_mutex_lock(&philo->meals_lock);
	philo->meal_eaten++;
	pthread_mutex_unlock(&philo->meals_lock);
}

static void	eating_alive(t_plato *philo)
{
	pthread_mutex_lock(&philo->state_of_philo);
	philo->alive = 1;
	philo->is_eating = 1;
	pthread_mutex_unlock(&philo->state_of_philo);
}

/* To start eating we need two forks*/
int	eats(t_plato *philo)
{
	t_table	*table;

	table = philo->table;
	if (table->array_size == 1)
		return ((take_forks(philo, 1)));
	else
	{
		if (!check_table(philo->table)
			&& philo->alive == 1)
		{
			if (take_forks(philo, 0))
				return (1);
			if (check_table(philo->table) == 0)
				console_write(philo->table, philo->name, EAT, GREEN);
			eating_alive(philo);
			update_time_meals(philo);
			my_usleep(philo->time_to_eat);
			return (drops_forks(philo));
		}
		return (1);
	}
}
