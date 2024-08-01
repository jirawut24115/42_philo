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

int	check_digit(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (1);
		s++;
	}
	return (0);
}

int	check_input(char **argv)
{
	int	i;
	
	i = 1;
	while (argv[i])
	{
		if (check_digit(argv[i]) || ft_atoi(argv[i]) < 0)
			return (-1);
		i++;
	}
	return (0);
}

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
		printf("Number of time each philosopher must eat : %d\n", rules->num_eat);
}

int	main(int argc, char **argv)
{
	t_rules	*rules;
	
	if ((argc != 5 && argc != 6) || check_input(argv))
	{
		printf("%s\n", USAGE);
		return (-1);
	}
	rules = malloc(sizeof(t_rules));
	if (!rules)
		return (-1);
	init_rules(argv, rules);
	print_rule(rules);
	free(rules);
	return (0);
}
