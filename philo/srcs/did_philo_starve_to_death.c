/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   did_philo_starve_to_death.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:01:53 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/28 23:49:57 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#include "did_philo_starve_to_death.h"

#include "actions/do_actions.h"
#include "timeval_ops.h"

int	kill_philo_if_he_starve_to_death(t_philo *philo)
{
	struct timeval	now;
	unsigned long	timestamp;

	if (did_philo_starve_to_death(philo))
	{
		pthread_mutex_lock(&philo->state->is_simulation_over_lock);
		gettimeofday(&now, 0);
		now = time_diff(now, philo->state->start);
		timestamp = now.tv_usec / 1000 + now.tv_sec * 1000;
		if (!philo->state->is_simulation_over)
			print_action(timestamp, philo->id, DIE_MSG);
		philo->state->is_simulation_over = 1;
		pthread_mutex_unlock(&philo->state->is_simulation_over_lock);
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
	did_philo_starve = philo->last_eat + philo->state->pi.time_to_die
		< (unsigned int)(timestamp.tv_usec / 1000 + timestamp.tv_sec * 1000);
	return (did_philo_starve);
}
