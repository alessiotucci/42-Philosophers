/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:41:14 by atucci            #+#    #+#             */
/*   Updated: 2023/10/11 09:46:20 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_routine(t_plato *the_array, int how_many)
{
	int count;

	count = 0;
	while (count < how_many)
	{
	pthread_create(&the_array[count].thread, NULL, routing, &the_array[count]);
	count++;
	}
	count = 0;
	while (count < how_many)
	{
	pthread_join(the_array[count].thread, NULL);
	count++;
	}
}


void	*routing(void *argum)
{
	t_plato	*philosopo;

	philosopo = (t_plato *)argum;
	printf("this philospher %d is doing his routine \n", philosopo->name);
	return (NULL);
}
