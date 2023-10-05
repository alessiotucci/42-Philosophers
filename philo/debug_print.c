/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:20:12 by atucci            #+#    #+#             */
/*   Updated: 2023/10/05 13:27:41 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_struct(t_philo *philo, int flag)
{
	printf("%show_many philosoper [%d]%s\n",GREEN, philo->how_many, RESET);
	printf("%stime to die ☠️ [%d]%s\n",RED, philo->time_to_die, RESET);
	printf("%stime to eat 🍝[%d]%s\n",YELLOW, philo->time_to_eat, RESET);
	printf("%stime to sleep 😴[%d]%s\n",YELLOW, philo->time_to_sleep, RESET);
	if (flag == 1)
		printf("%soften eat: [%d]\n%s",CYAN, philo->often_eat, RESET);
	else 
		printf("not specifies how often to eat\n");
}
