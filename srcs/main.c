/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jchompoo <jchompoo@student.42bangkok.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 20:29:46 by jchompoo          #+#    #+#             */
/*   Updated: 2024/07/28 11:10:40 by jchompoo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_rules(char **argv, t_rules *rules)
{
	rules->num_philo = ft_atoi(argv[1]);
	rules->time_die = ft_atoi(argv[2]);
	rules->time_eat = ft_atoi(argv[3]);
	rules->time_sleep = ft_atoi(argv[4]);
	if (argv[5])
		rules->num_eat = ft_atoi(argv[5]);
	else
		rules->num_eat = -1;
}

void	print_rule(t_rules *rules)
{
	printf("Number of philosopher : %d\n", rules->num_philo);
	printf("Time to die : %d\n", rules->time_die);
	printf("Time to eat : %d\n", rules->time_eat);
	printf("Time to sleep : %d\n", rules->time_sleep);
	if (rules->num_eat != -1)
		printf("Number of time each philosopher must eat : %d\n",
			rules->num_eat);
}

void	*routine(void *data)
{
	t_philo *philo = (t_philo *)data;
	
	int	i = 0;
	while (i < philo->num_eat)
	{
		pthread_mutex_lock(&philo->l_fork);
		pthread_mutex_lock(&philo->r_fork);
		sleep(1);
		gettimeofday(&philo->tv, NULL);
		printf("From thread %d on %ld\n", philo->a + 1, philo->tv.tv_usec);
		pthread_mutex_unlock(&philo->l_fork);
		pthread_mutex_unlock(&philo->r_fork);
		i++;
	}
	return (NULL);
}

int	main(int argc, char **argv)
{
	t_rules		*rules;

	if ((argc != 5 && argc != 6) || check_input(argv))
	{
		printf("%s\n", USAGE);
		return (-1);
	}
	rules = malloc(sizeof(t_rules));
	if (!rules)
		return (-1);
	init_rules(argv, rules);
	// creating philo array
	rules->philo = malloc(sizeof(t_philo) * rules->num_philo);
	rules->forks = malloc(sizeof(pthread_mutex_t) * rules->num_philo);
	int i = 0;

	while (i < rules->num_philo)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL) == -1)
			printf("Mutex error\n");
		i++;
	}
	i = 0;
	while (i < rules->num_philo)
	{
		rules->philo[i].a = i;
		rules->philo[i].num_eat = rules->num_eat;
		rules->philo[i].last_meal = 0;
		if (pthread_create(&rules->philo[i].th, NULL, &routine, (void *)&rules->philo[i]) == -1)
			printf("Thread error\n");
		rules->philo[i].l_fork = rules->forks[i];
		if (i == 0)
			rules->philo[i].r_fork = rules->forks[rules->num_philo - 1];
		else
			rules->philo[i].r_fork = rules->forks[i - 1];
		i++;
	}

	// joining threads
	i = 0;
	while (i < rules->num_philo)
	{
		pthread_join(rules->philo[i].th, NULL);
		i++;
	}
	i = 0;
	while (i < rules->num_philo)
	{
		pthread_mutex_destroy(&rules->forks[i]);
		i++;
	}
	free(rules->philo);
	free(rules->forks);
	free(rules);
	return (0);
}

