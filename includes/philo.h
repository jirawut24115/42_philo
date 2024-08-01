/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:30:36 by jchompoo          #+#    #+#             */
/*   Updated: 2024/07/28 11:05:40 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <stdio.h>
# include <pthread.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# define USAGE "Usage: ./philo <num1> <num2> <num3> <num4> [num5]\n\
num1: Numbers of Philosohers [1, 300]\n\
num2: If a philosopher didn’t start eating num2 milliseconds since \
the beginning of their last meal or the beginning of the simulation, they die.\n\
num3: The time(in milliseconds) it takes for a philosopher to eat.\
During that time, they will need to hold two forks.\n\
num4: The time(in milliseconds) a philosopher will spend sleeping.\n\
num5: If all philosophers have eaten at least num5 times, the simulation stops. \
If not specified, the simulation stops when a philosopher dies."

typedef struct s_philo
{
	pthread_t th;
	int		num_eat;
	int		last_meal;
	struct	timeval tv;
	int		a;
	pthread_mutex_t l_fork;
	pthread_mutex_t r_fork;
}	t_philo;

typedef struct s_rules
{
	int	num_philo;
	int	time_die;
	int	time_eat;
	int	time_sleep;
	int	num_eat;
	t_philo *philo;
	pthread_mutex_t *forks;
}	t_rules;

//parser
int	check_digit(char *s);
int	check_input(char **argv);

int	ft_atoi(char *s);

#endif