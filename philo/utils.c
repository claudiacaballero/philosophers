/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:33:16 by ccaballe          #+#    #+#             */
/*   Updated: 2023/06/19 18:06:30 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	ft_atol(char *str)
{
	int			i;
	long int	neg;
	long int	res;

	i = 0;
	neg = 1;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i] - '0');
		i++;
	}
	return (neg * res);
}

int	ft_error(char *s, t_params *params)
{
	printf("%s\n", s);
	ft_free(params);
	return (-1);
}

void	ft_free(t_params *params)
{
	int	i;

	free(params->philo);
	i = -1;
	while (++i < params->num_philo)
		pthread_mutex_destroy(&params->forks[i]);
	free(params->forks);
}
