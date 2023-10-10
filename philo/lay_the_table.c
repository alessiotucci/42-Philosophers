/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lay_the_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:58:14 by atucci            #+#    #+#             */
/*   Updated: 2023/10/10 14:44:58 by atucci           ###   ########.fr       */
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
	count++;
	}
	return (1);
}



int	lay_the_table(t_input *param,t_table *new_table)
{
	new_table->philly = (t_plato *)malloc(sizeof(t_plato) * param->how_many);
	if (new_table->philly == NULL)
		printf("memory allocation failed\n");
	else
		printf("%sAllocation was good, passing to the naming function%s\n", GREEN, RESET);
	new_table->philly_size = param->how_many;
	new_table->time_to_eat = param->time_to_eat;
	new_table->time_to_sleep = param->time_to_sleep;
	new_table->time_to_die = param->time_to_die;
		create_name_philos(new_table);
	return (0);
}
