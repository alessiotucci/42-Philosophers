/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:26:42 by atucci            #+#    #+#             */
/*   Updated: 2023/10/08 17:37:02 by atucci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdbool.h>

# define WRONG_INPUT 1
# define MALLOC_ERROR 2

# define TAKE_FORKS "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

/* Define color macros */
# define GREEN   "\033[1;32m"
# define CYAN    "\033[1;36m"
# define YELLOW  "\033[1;33m"
# define RED     "\033[1;31m"
# define RESET   "\033[0m"
/* Define Background colors macros */
# define BG_RESET        "\033[49m"
# define BG_GREEN        "\033[42m"
# define BG_CYAN         "\033[46m"
# define BG_YELLOW       "\033[43m"
# define BG_RED          "\033[41m"

/* this for testing */
typedef struct s_input
{
	int	how_many;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	often_eat;
}		t_input;
/**/
typedef struct s_plato
{
	pthread_t		thread;
	int		name;
	int		meal_eaten;
	size_t		last_time_eat;
	size_t		time_to_die;
	size_t		time_to_eat;
	size_t		time_to_sleep;
}		t_plato;
/* the table where the philosopher are sitting*/
typedef struct s_table
{
	t_plato		*philly;
}		t_table;
/* utils function */
int	ft_isdigit(int argum);
int	ft_atoi(const char *str);
/* modified version of time.h function*/
int	my_usleep(u_int64_t interlude);
u_int64_t	my_get_time(void);
/* lay the tables means gathering data off all the philos and forks*/
int	lay_the_table(void);
/* this function is for printing debugg*/
void print_struct(t_input *commmand, int flag);
#endif
