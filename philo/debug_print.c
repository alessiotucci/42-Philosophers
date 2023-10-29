/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:20:12 by atucci            #+#    #+#             */
/*   Updated: 2023/10/29 12:19:40 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Useful function that lock mutex and print with nice colors*/
u_int64_t	console_write(t_table *table, int name, char *message, char *color)
{
	u_int64_t	time;

	time = my_get_time() - table->time_of_start;
	pthread_mutex_lock(&table->writing);
	printf("%llu %d %s%s%s\n", time, name, color, message, RESET);
	pthread_mutex_unlock(&table->writing);
	return (my_get_time()); // little updated.
}

/* static function to check for inputs*/
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

/*function to print the info abot the  table*/
void	print_table(t_table *new_table)
{
	int	count;

	count = 0;
	printf("\n\n-----------NEW TABLE -------------\n");
	printf("|%sTable size is for [%d] philosphers%s|\n", BG_GREEN,new_table->array_size, BG_RESET);
	while (count < new_table->array_size)
	{
		if (count % 2)
			printf("\n|%s******* Philospher Name: %d ***********|%s\n",CYAN, new_table->array_of_philos[count].name, RESET);
		else
			printf("\n|%s******* Philospher Name: %d ***********|%s\n",YELLOW, new_table->array_of_philos[count].name, RESET);
			printf("|\tPhilospher meal eaten->%d\t|\n", new_table->array_of_philos[count].meal_eaten);
			printf("|\tPhilospher will die in %zums\t|\n", new_table->array_of_philos[count].time_to_die);
			printf("|\tPhilospher will eat%zums\t|\n", new_table->array_of_philos[count].time_to_eat);
			printf("|\tPhilospher will sleep%zums\t|\n", new_table->array_of_philos[count].time_to_sleep);
			printf("|\tPhilospher has to eat %d meals\t|\n", new_table->meals_to_eat);
	count++;
	}
	start_routine(new_table, new_table->array_size);

}

/* function to print out the struct, it uses a flag*/
void	print_struct(t_input *philo, int flag)
{
	if (check_input(philo) == 0)
	{
	printf("%show_many philosoper [%d]%s\n",BG_GREEN, philo->how_many, RESET);
	printf("%stime to die ☠️ [%d]%s\n",RED, philo->time_to_die, RESET);
	printf("%stime to eat 🍝[%d]%s\n",YELLOW, philo->time_to_eat, RESET);
	printf("%stime to sleep 😴[%d]%s\n",CYAN, philo->time_to_sleep, RESET);
	if (flag == 1)
		printf("%soften eat: [%d]\n%s",CYAN, philo->often_eat, RESET);
	else 
		printf("not specifies how often to eat\n");
	}
	return ;
}

