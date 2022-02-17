/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_infos.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:43:21 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/17 15:18:31 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOS_INFOS_H
# define PHILOS_INFOS_H

# include <pthread.h>
# include <sys/time.h>

typedef struct s_philos_infos
{
	int	n_philos;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	n_meals;
}	t_philos_infos;

typedef struct s_philo
{
	pthread_t	thread;
	int			last_meal;
	int			n_meals;
}	t_philo;

typedef struct s_world
{
	t_philos_infos	pi;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	struct timeval	*start_time;
}	t_world;

#endif
