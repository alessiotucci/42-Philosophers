/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 11:43:20 by atucci            #+#    #+#             */
/*   Updated: 2023/10/18 12:32:23 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

/* Function to free most of the stuff*/
void	free_all(t_table *old_table)
{
	free(old_table->philly);
	return ;
}
int	ft_isdigit(int argum)
{
	return (argum >= 48 && argum <= 57);
}

/* atoi since we cannot use libft*/
long	ft_atoi_plus(const char *s)
{
	long	num;
	long	sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'
		|| s[i] == '\v' || s[i] == '\f' || s[i] == '\r')
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		num = (num * 10) + (s[i] - '0');
		i++;
	}
	if ((sign * num) > INT_MAX || (sign * num) < INT_MIN)
		{
			printf("%sMAX INT OR MIN INT alert! be carefully%s", RED, RESET);
			exit(0);
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
/*This function is mainly for parsing the argumetns*/
void	parsing_argus(t_input *params, char *av[])
{
	params->how_many = ft_atoi_plus(av[1]);
	params->time_to_die = ft_atoi_plus(av[2]);
	params->time_to_eat = ft_atoi_plus(av[3]);
	params->time_to_sleep = ft_atoi_plus(av[4]);
}

/*THIS FILE ALREADY HAS 5 FUNCTIONS*/
