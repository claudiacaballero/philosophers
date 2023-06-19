/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 17:17:01 by ccaballe          #+#    #+#             */
/*   Updated: 2023/06/19 18:01:13 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(t_philo *philo)
{
	eat(philo);
	return (NULL);
}

void	eat(t_philo *philo)
{
	pthread_mutex_lock(&philo->params->forks[0]);
	printf("%i took the fork\n", philo->num);
	pthread_mutex_unlock(&philo->params->forks[0]);
}

// void	sleep(t_philo *philo)
// {}

// void	think(t_philo *philo)
// {}
