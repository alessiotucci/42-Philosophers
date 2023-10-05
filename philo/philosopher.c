/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:14:08 by atucci            #+#    #+#             */
/*   Updated: 2023/10/05 11:53:50 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	check_for_digits(char *str)
{
	size_t	count;

	count = 0;
	while (str[count])
	{
		if (!ft_isdigit(str[count]))
		{
			printf("%sOnly digits please%s\n", BG_RED, RESET);
			return ;
		}
		count++;
	}
}

int	main(int ac, char *av[])
{
	int	count;

	count = 1;
	if (ac != 5)
		return (printf("%s Wrong input %s\n", RED, RESET));
	while (count <= 4)
	{
		check_for_digits(av[count]);
		count++;
	}
	return (0);
}
