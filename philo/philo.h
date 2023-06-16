/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:41:04 by ccaballe          #+#    #+#             */
/*   Updated: 2023/06/15 17:14:27 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		thread;
	int				num;
	long int		last_ate;
}	t_philo;

typedef struct s_params
{
	int				num_philo;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	long int		number_meals;
	t_philo			*philo;
}	t_params;

//main
int			init_simulation(int ac, char **av, t_params *params);
int			create_threads(t_params *params);

//utils
long int	ft_atol(char *str);
void		free_list(t_params *params);
int			ft_error(char *s, t_params *params);

//routines
void		*start_routine();

#endif