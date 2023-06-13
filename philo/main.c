/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:40:32 by ccaballe          #+#    #+#             */
/*   Updated: 2023/06/13 17:57:32 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_params	params;

	if (ac < 5 || ac > 6)
		return (ft_error("ERROR\nExpected 4 or 5 arguments", &params));
	if (init_simulation(ac, av, &params) == -1)
		return (ft_error("ERROR\nCould not allocate memory", &params));
	create_threads(&params);
	free(params.philo);
	return (0);
}

int	init_simulation(int ac, char **av, t_params *params)
{
	int	i;

	i = -1;
	params->num_philo = ft_atol(av[1]);
	params->time_to_die = ft_atol(av[2]);
	params->time_to_eat = ft_atol(av[3]);
	params->time_to_sleep = ft_atol(av[4]);
	params->number_meals = 0;
	if (ac == 6)
		params->number_meals = ft_atol(av[5]);
	params->philo = malloc(sizeof(t_philo) * params->num_philo);
	if (!params->philo)
		return (-1);
	while (++i < params->num_philo)
	{
		params->philo[i].num = i + 1;
		params->philo[i].last_ate = 0;
	}
	//forquilles ?????
	//hora on comença per saber quanta estona ha passat
	return (0);
}

int	create_threads(t_params *params)
{
	int	i;

	i = -1;
	while (++i < params->num_philo)
		//start thread
	return (0);
}
