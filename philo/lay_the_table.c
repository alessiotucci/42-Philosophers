/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lay_the_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:58:14 by atucci            #+#    #+#             */
/*   Updated: 2023/10/11 12:23:17 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_name_philos(t_table *new_table)
{
	int	count;

	count = 0;
	while (count < new_table->philly_size)
	{
	new_table->philly[count].name = count + 1;
	new_table->philly[count].meal_eaten = 0;
	new_table->philly[count].time_to_die = new_table->time_to_die;
	new_table->philly[count].time_to_sleep = new_table->time_to_sleep;
	new_table->philly[count].time_to_eat = new_table->time_to_eat;
	pthread_mutex_init(&new_table->philly[count].state_of_philo, NULL);
	pthread_mutex_init(&new_table->philly[count].meals_philo_had, NULL);
	pthread_mutex_init(&new_table->philly[count].eat_last_time, NULL);
	count++;
	}
	return (1);
}

static void	set_table_mutexes(t_table *new_table)
{
	int	count;

	count = 0;
	printf("setting the mutexed\n");
	while (count < new_table->philly_size)
	{
	pthread_mutex_init(&new_table->few_forks[count], NULL); // this mutex will need to be destoyed
	count++;
}
		pthread_mutex_init(&new_table->writing, NULL); // this mutex will need to be destoyed
}

int	lay_the_table(t_input *param,t_table *new_table)
{
	new_table->philly = (t_plato *)malloc(sizeof(t_plato) * param->how_many);// this will need to be freed
	new_table->few_forks = malloc(sizeof(pthread_mutex_t) * param->how_many);// this will need to be freed
	if (new_table->philly == NULL)
		printf("memory allocation failed\n");
	else
		printf("%sAllocation was good, passing to the naming function%s\n", GREEN, RESET);
	new_table->philly_size = param->how_many;
	new_table->time_to_eat = param->time_to_eat;
	new_table->time_to_sleep = param->time_to_sleep;
	new_table->time_to_die = param->time_to_die;
	set_table_mutexes(new_table);
		create_name_philos(new_table);
	return (0);
}
