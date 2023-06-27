/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:17:01 by ccaballe          #+#    #+#             */
/*   Updated: 2023/06/27 17:12:38 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(t_philo *philo)
{
	while (!check_dead(philo, 1))
	{
		eat(philo);
		if (!check_dead(philo, 0))
			sleep_think(philo);
	}
	return (NULL);
}

void	eat(t_philo *philo)
{
	long long int	t;

	t = get_time() + philo->params->time_to_eat;
	pthread_mutex_lock(&philo->params->forks[philo->l_fork]);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->params->forks[philo->r_fork]);
	print_status(philo, "has taken a fork");
	print_status(philo, "is eating");
	philo->last_ate = get_time();
	while (get_time() <= t && !check_dead(philo, 0))
		usleep(200);
	pthread_mutex_unlock(&philo->params->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->params->forks[philo->r_fork]);
}

void	sleep_think(t_philo *philo)
{
	long long int	t;

	t = get_time() + philo->params->time_to_sleep;
	print_status(philo, "is sleeping");
	while (get_time() <= t && !check_dead(philo, 0))
		usleep(200);
	if (!check_dead(philo, 0))
		print_status(philo, "is thinking");
}

int	check_dead(t_philo *philo, int i)
{
	long long int	t;

	t = get_time() - philo->last_ate;
	if (t > philo->params->time_to_die)
	{
		if (i == 1)
			print_status(philo, "died");
		// philo->params->dead = 1;
		philo->dead = 1;
		return (1);
	}
	return (0);
}

int	print_status(t_philo *philo, char *s)
{
	pthread_mutex_lock(&philo->params->print);
	printf("%li %i %s\n", (get_time() - philo->params->start), philo->num, s);
	pthread_mutex_unlock(&philo->params->print);
	return (0);
}

// int	die(t_params *params)
// {
// 	//posar el kill count desde params directament aixi no es necessita mutex pel kc
// 	// ???? preguntarho
// }
