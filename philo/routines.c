/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:17:01 by ccaballe          #+#    #+#             */
/*   Updated: 2023/06/20 17:29:29 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(t_philo *philo)
{
	while(1)
		eat(philo);
	return (NULL);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->params->forks[philo->l_fork]);
	printf("%li %i has taken a fork\n", get_time(), philo->num);
	pthread_mutex_lock(&philo->params->forks[philo->r_fork]);
	printf("%li %i has taken a fork\n", get_time(), philo->num);
	usleep(philo->params->time_to_eat * 1000);
	pthread_mutex_unlock(&philo->params->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->params->forks[philo->r_fork]);
	printf("%i finished eating\n", philo->num);
}

// void	sleep(t_philo *philo)
// {}

// void	think(t_philo *philo)
// {}
