/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccaballe <ccaballe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 16:41:04 by ccaballe          #+#    #+#             */
/*   Updated: 2023/06/06 17:35:09 by ccaballe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <thread.h>

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
void	ft_error(char *s);

//utils
int	ft_atoi(char *str);

#endif