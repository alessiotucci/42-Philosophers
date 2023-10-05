/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:14:08 by atucci            #+#    #+#             */
/*   Updated: 2023/10/05 12:56:37 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	check_for_digits(char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
	{
		if (!ft_isdigit(str[count]))
		{
			printf("%sOnly digits please%s\n", BG_RED, RESET);
			return (0);
		}
		count++;
	}
return (1);
}

int	main(int ac, char *av[])
{
	int	count;
	t_philo	test;

	count = 1;
	if (ac < 5 || ac > 6)
		return (printf("%s Wrong input %s\n", RED, RESET));
	while (count <= 4)
	{
		(check_for_digits(av[count]));
		count++;
	}
	test.how_many = ft_atoi(av[1]);
	test.time_to_die = ft_atoi(av[2]);
	test.time_to_eat = ft_atoi(av[3]);
	test.time_to_sleep = ft_atoi(av[4]);
	if (av[5])
	test.often_eat = ft_atoi(av[5]);
	print_struct(&test);
	return (0);
}
