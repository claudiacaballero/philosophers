/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 17:33:16 by ccaballe          #+#    #+#             */
/*   Updated: 2023/06/06 19:22:08 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	ft_atoi(char *str)
{
	int	i;
	int	neg;
	int	res;

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

void	free_list(t_params *params)
{
	t_philo	*tmp;

	while (params->philo)
	{
		tmp = params->philo->next;
		free(params->philo);
		params->philo = tmp;
	}
}

int	ft_error(char *s, t_params *params)
{
	printf("%s\n", s);
	free_list(params);
	return (-1);
}
