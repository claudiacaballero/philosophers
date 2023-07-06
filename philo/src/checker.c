/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:46:41 by ccaballe          #+#    #+#             */
/*   Updated: 2023/07/06 17:42:32 by ccaballe         ###   ########.fr       */
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

	t = get_time() - philo->last_ate;
	if (t > philo->params->time_to_die)
	{
		philo->dead = 1;
		if (i == 1)
			print_status(philo, "died");
		return (1);
	}
	return (0);
}

int	check_philos(t_params *params)
{
	int	d;
	int	i;

	d = 0;
	while (d == 0)
	{
		i = -1;
		while (++i < params->num_philo)
		{
			if (check_dead(&params->philo[i], 1))
			{
				d = 1;
				break ;
			}
		}
	}
	return (1);
}
