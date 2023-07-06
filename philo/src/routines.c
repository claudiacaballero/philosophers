/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:17:01 by ccaballe          #+#    #+#             */
/*   Updated: 2023/07/06 18:15:27 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	*routine(t_philo *philo)
{
	while (!check_dead(philo, 1))
	{
		eat(philo);
		if (philo->ate_count == philo->params->number_meals)
			philo->done = 1;
		if (!check_dead(philo, 0))
			sleep_think(philo);
	}
	return (NULL);
}

void	eat(t_philo *philo)
{
	long long int	t;

	pthread_mutex_lock(&philo->params->forks[philo->l_fork]);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->params->forks[philo->r_fork]);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->params->update);
	print_status(philo, "is eating");
	t = get_time() + philo->params->time_to_eat;
	pthread_mutex_unlock(&philo->params->update);
	philo->last_ate = get_time();
	while (get_time() <= t && !check_dead(philo, 0))
		usleep(200);
	philo->ate_count++;
	pthread_mutex_unlock(&philo->params->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->params->forks[philo->r_fork]);
}

void	sleep_think(t_philo *philo)
{
	long long int	t;

	print_status(philo, "is sleeping");
	t = get_time() + philo->params->time_to_sleep;
	while (get_time() <= t && !check_dead(philo, 0))
		usleep(200);
	if (!check_dead(philo, 0))
		print_status(philo, "is thinking");
}

int	print_status(t_philo *philo, char *s)
{
	pthread_mutex_lock(&philo->params->print);
	printf("%04li\t%i\t%s\n", (get_time() - philo->params->start), philo->num, s);
	if (philo->dead != 1)
		pthread_mutex_unlock(&philo->params->print);
	return (0);
}
