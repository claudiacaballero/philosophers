/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:40:32 by ccaballe          #+#    #+#             */
/*   Updated: 2023/07/06 17:11:13 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_params	params;

	if (!valid_args(ac, av))
		return (ft_error("ERROR\nPlease enter 4 or 5 positive integers", NULL));
	//protegir prints, mutex inits i gettimeofday :)
	if (init_params(ac, av, &params) == -1)
		return (ft_error("ERROR\nCould not allocate memory", &params));
	create_threads(&params);
	check_philos(&params);
	usleep(500000); // comprobacion de q todos los hilos han terminado
	ft_free(&params);
	return (0);
}

int	init_params(int ac, char **av, t_params *params)
{

	params->num_philo = ft_atol(av[1]);
	params->time_to_die = ft_atol(av[2]);
	params->time_to_eat = ft_atol(av[3]);
	params->time_to_sleep = ft_atol(av[4]);
	params->number_meals = 0;
	pthread_mutex_init(&params->print, NULL);
	pthread_mutex_init(&params->update, NULL);
	params->start = get_time();
	if (ac == 6)
		params->number_meals = ft_atol(av[5]);
	if (init_arrays(params) == -1)
		return (-1);
	return (0);
}

int	init_arrays(t_params *params)
{
	int	i;

	i = -1;
	params->philo = malloc(sizeof(t_philo) * params->num_philo);
	if (!params->philo)
		return (-1);
	while (++i < params->num_philo)
	{
		params->philo[i].num = i + 1;
		params->philo[i].dead = 0;
		params->philo[i].params = params;
		params->philo[i].last_ate = get_time();
		params->philo[i].ate_count = 0;
		params->philo[i].l_fork = i;
		params->philo[i].r_fork = i + 1;
		if (i == params->num_philo - 1)
			params->philo[i].r_fork = 0;
	}
	params->forks = malloc(sizeof(pthread_mutex_t) * params->num_philo);
	if (!params->forks)
		return (-1);
	i = -1;
	while (++i < params->num_philo)
		pthread_mutex_init(&params->forks[i], NULL);
	return (0);
}

int	create_threads(t_params *params)
{
	int	i;

	i = -1;
	while (++i < params->num_philo)
	{
		pthread_create(&params->philo[i].thread, NULL, \
			(void *)routine, &params->philo[i]);
		usleep(100);
	}
	return (0);
}
