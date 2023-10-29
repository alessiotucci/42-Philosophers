/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lay_the_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:58:14 by atucci            #+#    #+#             */
/*   Updated: 2023/10/29 12:24:46 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	create_name_philos(t_table *new_table)
{
	int	count;

	count = 0;
	while (count < new_table->array_size)
	{
	new_table->array_of_philos[count].table = new_table;
	new_table->array_of_philos[count].name = count + 1;
	new_table->array_of_philos[count].meal_eaten = 0;
	new_table->array_of_philos[count].alive = 1;
//	new_table->philly[count].last_time_eat = 0; //my_get_time();
	new_table->array_of_philos[count].time_to_die = new_table->time_to_die;
	new_table->array_of_philos[count].time_to_sleep = new_table->time_to_sleep;
	new_table->array_of_philos[count].time_to_eat = new_table->time_to_eat;
	pthread_mutex_init(&new_table->array_of_philos[count].state_of_philo, NULL);
	pthread_mutex_init(&new_table->array_of_philos[count].meals_lock, NULL);
	pthread_mutex_init(&new_table->array_of_philos[count].eat_last_time, NULL);
	count++;
	}
	return (1);
}
static void	assign_forks_to_philos(t_table *table)
{
	int	count;
	t_plato	*philosophi;
	int	last_philo_index;

	last_philo_index = table->array_size- 1;
	philosophi = table->array_of_philos;
	// special case for the first philopher to be connected with the last one
	philosophi[0].left_fork = &table->few_forks[0];
	philosophi[0].right_fork = &table->few_forks[last_philo_index];
	// we set up the fork to be shared across the table from the philosphers
	count = 1;
	// special case for the first philopher to be connected with the last one
	while (count <= last_philo_index)
	{
	philosophi[count].left_fork = &table->few_forks[count];
	philosophi[count].right_fork = &table->few_forks[count - 1];
	count++;
	}
}

/* the name is self descriptivie..*/
static void	set_table_mutexes(t_table *new_table)
{
	int	count;

	count = 0;
	printf("setting the mutexed\n");
	while (count < new_table->array_size)
	{
	pthread_mutex_init(&new_table->few_forks[count], NULL); // this mutex will need to be destoyed
	count++;
	}
		pthread_mutex_init(&new_table->writing, NULL); // this mutex will need to be destoyed
		assign_forks_to_philos(new_table);
}

/* Laying the table means get the struct table ready */
int	lay_the_table(t_input *param,t_table *new_table)
{
	new_table->array_of_philos= (t_plato *)malloc(sizeof(t_plato) * param->how_many);// this will need to be freed
	new_table->few_forks = malloc(sizeof(pthread_mutex_t) * param->how_many);// this will need to be freed
	if (new_table->array_of_philos== NULL)
		printf("memory allocation failed\n");
	else
		printf("%sAllocation was good, passing to the naming function%s\n", GREEN, RESET);
	new_table->meals_to_eat = param->often_eat;
	new_table->array_size = param->how_many;
	new_table->time_to_eat = param->time_to_eat;
	new_table->time_to_sleep = param->time_to_sleep;
	new_table->time_to_die = param->time_to_die;
	// check 
	new_table->someone_is_dead = 0;
	new_table->enough_is_enough = 0;
	set_table_mutexes(new_table);
	create_name_philos(new_table);
	return (0);
}
