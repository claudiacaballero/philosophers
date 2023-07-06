/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:33:16 by ccaballe          #+#    #+#             */
/*   Updated: 2023/07/06 17:42:51 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_isdigit(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
	{
		if (s[i] < '0' && s[i] > '9')
			return (0);
	}
	return (1);
}

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
	if (params)
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
	pthread_mutex_destroy(&params->print);
	pthread_mutex_destroy(&params->update);
	free(params->forks);
}

long int	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}
