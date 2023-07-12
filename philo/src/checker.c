/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:46:41 by ccaballe          #+#    #+#             */
/*   Updated: 2023/07/12 15:40:13 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	valid_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 5 || ac > 6)
		return (0);
	while (++i < ac)
	{
		if (!ft_isdigit(av[i]))
			return (0);
		else if (ft_atol(av[i]) <= 0 || ft_atol(av[i]) < INT_MIN \
			|| ft_atol(av[i]) > INT_MAX)
			return (0);
	}
	return (1);
}

int	check_dead(t_philo *philo, int i)
{
	long long int	t;

	pthread_mutex_lock(&philo->params->update);
	t = get_time() - philo->last_ate;
	if (t > philo->params->time_to_die)
	{
		pthread_mutex_lock(&philo->params->done);
		philo->dead = 1;
		pthread_mutex_unlock(&philo->params->done);
		if (i == 1)
			print_status(philo, "died");
		pthread_mutex_unlock(&philo->params->update);
		return (1);
	}
	pthread_mutex_unlock(&philo->params->update);
	return (0);
}

int	check_philos(t_params *params)
{
	int	i;

	while (params->any_dead == 0)
	{
		i = -1;
		while (++i < params->num_philo && !check_dead(&params->philo[i], 1))
			;
		if (i != params->num_philo)
		{
			pthread_mutex_lock(&params->done);
			params->any_dead = 1;
			pthread_mutex_unlock(&params->done);
		}
		if (check_finished_philos(params))
		{
			pthread_mutex_lock(&params->print);
			printf("everyone finished eating\n");
			pthread_mutex_unlock(&params->print);
			break ;
		}
	}
	i = -1;
	while (++i < params->num_philo)
		pthread_join(params->philo[i].thread, NULL);
	return (1);
}

int	check_finished_philos(t_params *params)
{
	int	i;

	i = -1;
	while (++i < params->num_philo)
	{
		pthread_mutex_lock(&params->done);
		if (!params->philo[i].done)
		{
			pthread_mutex_unlock(&params->done);
			return (0);
		}
		pthread_mutex_unlock(&params->done);
	}
	return (1);
}
