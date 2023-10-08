/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:20:12 by atucci            #+#    #+#             */
/*   Updated: 2023/10/08 14:46:58 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_input(t_input *phil)
{
	if (phil->how_many < 0)
		return (printf("%sPhilosopher cannot be less than zero%s", RED, RESET));
	if (phil->time_to_die < 0)
		return (printf("%sTime to die is negative%s\n", RED, RESET));
	if (phil->time_to_eat < 0)
		return (printf("%sTime to eat is negative%s\n", RED, RESET));
if (phil->time_to_sleep < 0)
		return (printf("%sTime to sleep is negative%s\n", RED, RESET));
	printf("%sThe input has been checked%s\n", GREEN, RESET);
	return (0);
}
void	print_struct(t_input *philo, int flag)
{
	if (check_input(philo) == 0)
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
	return ;
}
