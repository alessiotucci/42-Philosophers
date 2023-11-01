/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lay_the_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:58:14 by atucci            #+#    #+#             */
/*   Updated: 2023/11/01 16:25:13 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	create_name_philos(t_table *new_table)
{
	int	c;

	c = 0;
	while (c < new_table->array_size)
	{
		new_table->array_of_philos[c].table = new_table;
		new_table->array_of_philos[c].name = c + 1;
		new_table->array_of_philos[c].meal_eaten = 0;
		new_table->array_of_philos[c].alive = 1;
		new_table->array_of_philos[c].philo_is_full = 0;
		new_table->array_of_philos[c].time_to_die = new_table->time_to_die;
		new_table->array_of_philos[c].time_to_sleep = new_table->time_to_sleep;
		new_table->array_of_philos[c].time_to_eat = new_table->time_to_eat;
		pthread_mutex_init(&new_table->array_of_philos[c].state_of_philo, NULL);
		pthread_mutex_init(&new_table->array_of_philos[c].meals_lock, NULL);
		pthread_mutex_init(&new_table->array_of_philos[c].eat_last_time, NULL);
		c++;
	}
	return (1);
}

/*static function to assign mutexes to philos*/
static void	assign_forks_to_philos(t_table *table)
{
	int		count;
	t_plato	*philosophi;
	int		last_philo_index;

	last_philo_index = table->array_size - 1;
	philosophi = table->array_of_philos;
	philosophi[0].left_fork = &table->few_forks[0];
	philosophi[0].right_fork = &table->few_forks[last_philo_index];
	count = 1;
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
	printf("\n\n\n");
	while (count < new_table->array_size)
	{
		pthread_mutex_init(&new_table->few_forks[count], NULL);
		count++;
	}
	pthread_mutex_init(&new_table->writing, NULL);
	assign_forks_to_philos(new_table);
}

/*   Function to free most of the stuff*/
void	free_all(t_table *old_table)
{
	free(old_table->few_forks);
	free(old_table->array_of_philos);
	return ;
}

/* Laying the table means get the struct table ready */
int	lay_the_table(t_input *param, t_table *new_table)
{
	new_table->array_of_philos = (t_plato *)
		malloc(sizeof(t_plato) * param->how_many);
	new_table->few_forks = malloc(sizeof(pthread_mutex_t) * param->how_many);
	if (new_table->array_of_philos == NULL)
	{
		printf("memory allocation failed\n");
		exit(0);
	}
	new_table->meals_to_eat = param->often_eat;
	new_table->array_size = param->how_many;
	new_table->time_to_eat = param->time_to_eat;
	new_table->time_to_sleep = param->time_to_sleep;
	new_table->time_to_die = param->time_to_die;
	new_table->someone_is_dead = 0;
	new_table->enough_is_enough = 0;
	set_table_mutexes(new_table);
	create_name_philos(new_table);
	start_routine(new_table, new_table->array_size);
	return (0);
}
