/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 12:20:12 by atucci            #+#    #+#             */
/*   Updated: 2023/11/01 19:27:49 by atucci           ###   ########.fr       */
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
	return (my_get_time());
}

/* static function to check for inputs*/
int	check_input(t_input *input)
{
	if (input->how_many <= 0)
		return (printf("%sPhilo cant be less than zero%s\n", RED, RESET));
	if (input->time_to_die <= 0)
		return (printf("%sTime to die is negative%s\n", RED, RESET));
	if (input->time_to_eat <= 0)
		return (printf("%sTime to eat is negative%s\n", RED, RESET));
	if (input->time_to_sleep <= 0)
		return (printf("%sTime to sleep is negative%s\n", RED, RESET));
	if (input->often_eat < 0)
		return (printf("%sMeals is negative%s\n", RED, RESET));
	printf("%sThe input has been checked%s\n", GREEN, RESET);
	return (0);
}

/*function to print the info abot the  table*/
void	print_table(t_table *new_table)
{
	int	c;

	c = 0;
	printf("\n\n|\tNEW TABLE\t|\n");
	printf("|%sTable size [%d] philo%s   |\n", BG_GREEN,
		new_table->array_size, BG_RESET);
	while (c < new_table->array_size)
	{
		printf("\n\tPhiloName %d\t|\n", new_table->array_of_philos[c].name);
		printf("meal eaten %d\t\t|\n",
			new_table->array_of_philos[c].meal_eaten);
		printf("die in %zums\t\t|\n",
			new_table->array_of_philos[c].time_to_die);
		printf("eat %zums\t\t|\n",
			new_table->array_of_philos[c].time_to_eat);
		printf("sleep %zums\t\t|\n",
			new_table->array_of_philos[c].time_to_sleep);
		printf("thas to eat %d meal\t|\n", new_table->meals_to_eat);
		printf("------------------------\n\n");
		c++;
	}
	start_routine(new_table, new_table->array_size);
}

/* function to print out the struct, it uses a flag*/
void	print_struct(t_input *philo, int flag)
{
	if (check_input(philo) == 0)
	{
		printf("%show_many philo [%d]%s\n", BG_GREEN, philo->how_many, RESET);
		printf("%stime to die ☠️ [%d]%s\n", RED, philo->time_to_die, RESET);
		printf("%stime to eat 🍝[%d]%s\n", YELLOW, philo->time_to_eat, RESET);
		printf("%stime to sleep 😴[%d]%s\n", CYAN, philo->time_to_sleep, RESET);
		if (flag == 1)
			printf("%soften eat: [%d]\n%s", CYAN, philo->often_eat, RESET);
		else
			printf("not specifies how often to eat\n");
	}
	return ;
}
