/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 16:41:14 by atucci            #+#    #+#             */
/*   Updated: 2023/10/11 11:39:29 by atucci           ###   ########.fr       */
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
	printf("%d has finished their routing\n", the_array[count].name);
	count++;
	}
}


void	*routing(void *argum)
{
	t_plato	*philosopo;

	philosopo = (t_plato *)argum;
	// lock the mutex
	printf("%d is doing his routine \n", philosopo->name);
	// unlock the mutex
	return (NULL);
}
