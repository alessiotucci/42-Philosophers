/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lay_the_table.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 15:58:14 by atucci            #+#    #+#             */
/*   Updated: 2023/10/10 13:48:11 by atucci           ###   ########.fr       */
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
	count++;
	}
	return (1);
}



int	lay_the_table(t_input *param,t_table *new_table)
{
	if (param)
		printf("param is existing\n");
	if (new_table)
		printf("new table is existing\n");
	new_table->philly = (t_plato *)malloc(sizeof(t_plato) * param->how_many);
	if (new_table->philly == NULL)
		printf("memory allocation failed\n");
	else
		printf("%sAllocation was good, passing to the naming function%s\n", GREEN, RESET);
	new_table->philly_size = param->how_many;
		create_name_philos(new_table);
	return (0);
}
