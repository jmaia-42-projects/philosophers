/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   did_philo_starve_to_death.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:01:53 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/28 21:38:36 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <stdio.h>

#include "did_philo_starve_to_death.h"

#include "actions/do_actions.h"
#include "timeval_ops.h"

int	kill_philo_if_he_starve_to_death(t_philo *philo)
{
	int				i;
	struct timeval	now;
	unsigned long	timestamp;

	i = 0;
	if (did_philo_starve_to_death(philo))
	{
		sem_wait(philo->state->write_lock);
		gettimeofday(&now, 0);
		now = time_diff(now, philo->state->start);
		timestamp = now.tv_usec / 1000 + now.tv_sec * 1000;
		print_action(timestamp, philo->id, DIE_MSG);
		while (i < philo->state->pi.n_philos)
		{
			sem_post(philo->state->end_simulation_lock);
			i++;
		}
		return (0);
	}
	return (1);
}

int	did_philo_starve_to_death(t_philo *philo)
{
	struct timeval	now;
	struct timeval	timestamp;
	int				did_philo_starve;

	gettimeofday(&now, 0);
	timestamp = time_diff(now, philo->state->start);
	sem_wait(philo->last_eat_lock);
	did_philo_starve = philo->last_eat + philo->state->pi.time_to_die
		< (unsigned int)(timestamp.tv_usec / 1000 + timestamp.tv_sec * 1000);
	sem_post(philo->last_eat_lock);
	return (did_philo_starve);
}
