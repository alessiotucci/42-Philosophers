/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:14:08 by atucci            #+#    #+#             */
/*   Updated: 2023/11/01 15:46:59 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/*	1 means alive
	 0 means death 	
 */
int	check_table(t_table *table_to_check)
{
	int	result;

	pthread_mutex_lock(&table_to_check->lock_table);
	result = table_to_check->someone_is_dead;
	pthread_mutex_unlock(&table_to_check->lock_table);
	return (result);
}

static int	check_for_digits(char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
	{
		if (!ft_isdigit(str[count]))
		{
			printf("%sOnly digits please%s\n", BG_RED, RESET);
			exit(0);
		}
		count++;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	int		count;
	t_input	test;
	int		flag;
	t_table	nice_table;

	flag = 0;
	count = 1;
	if (ac < 5 || ac > 6)
		return (printf("%s Wrong input %s\n", RED, RESET));
	while (count <= 5)
		if (av[count])
			(check_for_digits(av[count++]));
	parsing_argus(&test, av);
	if (av[5])
	{
		test.often_eat = ft_atoi_plus(av[5]);
		flag = 1;
	}
	else
		test.often_eat = 0;
	lay_the_table(&test, &nice_table);
	free_all(&nice_table);
	return (0);
}

/*print struct to check the struct */
/*print table with nice table */
