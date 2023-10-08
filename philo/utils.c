/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:43:20 by atucci            #+#    #+#             */
/*   Updated: 2023/10/08 13:49:42 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int argum)
{
	return (argum >= 48 && argum <= 57);
}

int	ft_atoi(const char *str)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
		sign = -1;
	i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = (num * 10) + (str[i] - '0');
		i++;
	}
	return (sign * num);
}

/*The gettimeofday() function gets the system’s clock time*/
/*The current time is expressed in elapsed seconds and microseconds since
	* 00:00:00, January 1, 1970 (Unix Epoch).*/
u_int64_t	my_get_time(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
		return (printf("error with the gettimeofday()\n"));
	return ((time.tv_sec * (u_int64_t)1000) + (time.tv_usec / 1000));
}

/* This function is a better version of the Usleep
	* It is more accurate and has a better precision*/
int	my_usleep(u_int64_t interlude)
{
	u_int64_t	start;

	start = my_get_time();
	while ((my_get_time() - start) < interlude)
		usleep(interlude / 100);
	return (0);
}
