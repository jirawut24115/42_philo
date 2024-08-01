/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jichompo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 15:58:32 by jichompo          #+#    #+#             */
/*   Updated: 2024/08/01 15:58:34 by jichompo         ###   ########.fr       */
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