/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:41:04 by ccaballe          #+#    #+#             */
/*   Updated: 2023/06/06 19:20:21 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>


typedef struct s_philo
{
	int				num;
	int				last_ate;
	struct s_philo	*next;
}	t_philo;

typedef struct s_params
{
	int		num_philosophers;
	int		time_to_die;
	int		time_to_eat;
	int		time_to_sleep;
	int		number_meals;
	t_philo	*philo;
}	t_params;

//main
int		init_simulation(int ac, char **av, t_params *params);

//utils
int		ft_atoi(char *str);
void	free_list(t_params *params);
int		ft_error(char *s, t_params *params);

#endif