/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atucci <atucci@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 13:26:42 by atucci            #+#    #+#             */
/*   Updated: 2023/11/01 15:26:30 by atucci           ###   ########.fr       */
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

//# define INT_MIN 2147483647
# include <limits.h>
//# define INT_MAX -2147483647
# define WRONG_INPUT 1
# define MALLOC_ERROR 2

# define TAKE_FORK "has taken a fork"
# define THINK "is thinking"
# define SLEEP "is sleeping"
# define EAT "is eating"
# define DIED "died"

/* Define color macros */
# define BLUE    "\033[1;34m"
# define PURPLE  "\033[1;35m"
# define GRAY    "\033[1;30m"
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

/* this for testing, useful to
* parse the input correctly*/
typedef struct s_input
{
	int	how_many;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	often_eat;
}		t_input;

/* this is the struct for a philospher
	* I call it plato tho*/
typedef struct s_plato
{
	struct s_table		*table;
	pthread_t			thread;
	int					name;
	pthread_mutex_t		state_of_philo;
	int					alive;
	int					is_eating;
	pthread_mutex_t		meals_lock;
	int					meal_eaten;
	int					philo_is_full;
	pthread_mutex_t		eat_last_time;
	size_t				last_time_eat;
	size_t				time_to_die;
	size_t				time_to_eat;
	size_t				time_to_sleep;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
}		t_plato;

/* the table where the philosopher are sitting
	* they are sharing the forks of course*/
typedef struct s_table
{
	t_plato			*array_of_philos;
	int				array_size;
	pthread_mutex_t	*few_forks;
	pthread_mutex_t	lock_table;
	pthread_mutex_t	writing;
	int				someone_is_dead;
	int				enough_is_enough;
	int				meals_to_eat;
	pthread_t		monitor;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	u_int64_t		time_of_start;
}		t_table;

/* utils function */
int			ft_isdigit(int argum);
long		ft_atoi_plus(const char *str);

/* modified version of time.h function*/
int			my_usleep(u_int64_t interlude);
u_int64_t	my_get_time(void);

/* lay the tables means gathering data off all the philos and forks*/
int			lay_the_table(t_input *params, t_table *new_table);

/* this function is for printing debugg*/
void		print_struct(t_input *commmand, int flag);
void		print_table(t_table *new_table);
void		parsing_argus(t_input *params, char *av[]);
void		start_routine(t_table *the_table, int how_many);
void		*routing(void *argum);
void		free_all(t_table *old_table);
void		*monitoring(void *argum);
void		print_exit(int p);
/* Action of the routine*/
int			eats(t_plato *philo);
u_int64_t	console_write(t_table *table, int name, char *message, char *color);

/*useful function to monitor the death*/
int			check_table(t_table *table_to_check);
#endif
