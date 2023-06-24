/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:17:01 by ccaballe          #+#    #+#             */
/*   Updated: 2023/06/24 22:10:35 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(t_philo *philo)
{
	while (1)
	{
		eat(philo);
		sleep_think(philo);
	}
	return (NULL);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->params->forks[philo->l_fork]);
	printf("%li %i has taken a fork\n", \
		(get_time() - philo->params->start), philo->num);
	pthread_mutex_lock(&philo->params->forks[philo->r_fork]);
	printf("%li %i has taken a fork\n", \
		(get_time() - philo->params->start), philo->num);
	printf("%li %i is eating\n", \
		(get_time() - philo->params->start), philo->num);
	philo->last_ate = get_time();
	usleep(philo->params->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->params->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->params->forks[philo->r_fork]);
}

void	sleep_think(t_philo *philo)
{
	printf("%li %i is sleeping\n", \
		(get_time() - philo->params->start), philo->num);
	usleep(philo->params->time_to_sleep * 1000);
	printf("%li %i is thinking\n", \
		(get_time() - philo->params->start), philo->num);
}

int	check_dead(t_philo *philo)
{
	long int	t;

	t = get_time() - philo->last_ate;
	if (t > philo->params->time_to_die)
	{
		philo->params->dead = 1;
		printf("%li %i died\n", \
			(get_time() - philo->params->start), philo->num);
		return (1);
	}
	return (0);
}

int	die(t_params *params)
{
	//posar el kill count desde params directament aixi no es necessita mutex pel kc
	// ???? preguntarho
}
