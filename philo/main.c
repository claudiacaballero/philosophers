/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:40:32 by ccaballe          #+#    #+#             */
/*   Updated: 2023/06/06 19:22:18 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_params	params;

	if (ac < 5 || ac > 6)
		return (ft_error("ERROR\nExpected 4 or 5 arguments"));
	if (init_simulation(ac, av, &params) == -1)
		return (1);
	// while (params.philo)
	// {
	// 	printf("num philosopher = %i\n", params.philo->num);
	// 	params.philo = params.philo->next;
	// }
	return (0);
}

int	init_simulation(int ac, char **av, t_params *params)
{
	int		i;
	t_philo	*philo;
	t_philo	*tmp;

	i = 1;
	philo = (t_philo *)malloc(sizeof(t_philo));
	philo->num = 1;
	philo->last_ate = 0;
	philo->next = NULL;
	params->num_philosophers = ft_atoi(av[1]);
	params->time_to_die = ft_atoi(av[2]);
	params->time_to_eat = ft_atoi(av[3]);
	params->time_to_sleep = ft_atoi(av[4]);
	params->number_meals = 0;
	if (ac == 6)
		params->number_meals = ft_atoi(av[5]);
	params->philo = philo;
	while (i < ft_atoi(av[1]))
	{
		tmp = (t_philo *)malloc(sizeof(t_philo));
		if (!tmp)
			return (ft_error("ERROR\nCould not allocate memory", params));
		tmp->num = ++i;
		tmp->last_ate = 0;
		tmp->next = NULL;
		philo->next = tmp;
		philo = philo->next;
	}
	return (0);
}
