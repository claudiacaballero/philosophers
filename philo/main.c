/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:40:32 by ccaballe          #+#    #+#             */
/*   Updated: 2023/06/06 17:32:46 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	main(int ac, char **av)
{
	t_params	params;

	if (ac < 5 || ac > 6)
		return (ft_error("ERROR\nExpected 4 or 5 arguments"));
	init_simulation(av, params);
}

int	init_simulation(char **av, t_params params, t_philo philo)
{
	int	i;

	i = -1;
	while (i < )
}

void	ft_error(char *s)
{
	printf("%s\n", s);
	return ;
}
