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

typedef struct s_params	t_params;

typedef struct s_philo
{
	pthread_t		thread;
	int				num;
	long long int	last_ate;
	long int		ate_count;
	int				l_fork;
	int				r_fork;
	int				dead;
	t_params		*params;
}	t_philo;

struct s_params
{
	long int		start;
	long int		num_philo;
	long int		time_to_die;
	long int		time_to_eat;
	long int		time_to_sleep;
	long int		number_meals;
	t_philo			*philo;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
};

//main
int			init_params(int ac, char **av, t_params *params);
int			init_arrays(t_params *params);
int			create_threads(t_params *params);

//utils
long int	ft_atol(char *str);
int			ft_error(char *s, t_params *params);
void		ft_free(t_params *params);
long int	get_time(void);
int			check_philos(t_params *params);

//routines
void		*routine(t_philo *philo);
void		eat(t_philo *philo);
void		sleep_think(t_philo *philo);
int			check_dead(t_philo *philo, int i);
int			print_status(t_philo *philo, char *s);

#endif