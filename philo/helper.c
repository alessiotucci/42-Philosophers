/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 15:23:21 by atucci            #+#    #+#             */
/*   Updated: 2023/11/01 18:53:31 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_exit(int p)
{
	printf("%sMAX INT OR MIN INT alert! be careful%s", RED, RESET);
	exit(p);
}

void	do_it_all(t_input *test, int flag, t_table *nice_table)
{
	print_struct(test, flag);
	lay_the_table(test, nice_table);
	print_table(nice_table);
	free_all(nice_table);
}
