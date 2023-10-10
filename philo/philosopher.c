/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:14:08 by atucci            #+#    #+#             */
/*   Updated: 2023/10/10 12:51:30 by atucci           ###   ########.fr       */
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
	int		count;
	t_input	test;
	int		flag;

	flag = 0;
	count = 1;
	if (ac < 5 || ac > 6)
		return (printf("%s Wrong input %s\n", RED, RESET));
	while (count <= 5)
	{
		if (av[count])
			(check_for_digits(av[count]));
		count++;
	}
	parsing_argus(&test, av);
	if (av[5])
	{
		test.often_eat = ft_atoi(av[5]);
		flag = 1;
	}
	print_struct(&test, flag);
	lay_the_table();
	return (0);
}
