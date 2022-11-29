/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:13:32 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/28 21:07:58 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#include "actions/actions.h"

#include "actions/do_actions.h"
#include "ft_wait.h"
#include "timeval_ops.h"

int	ph_eat(t_philo *philo)
{
	int				err;
	struct timeval	now;

	ph_take_fork(philo);
	if (philo->state->pi.n_philos > 1)
	{
		ph_take_fork(philo);
		gettimeofday(&now, 0);
		now = time_diff(now, philo->state->start);
		sem_wait(philo->last_eat_lock);
		philo->last_eat = now.tv_usec / 1000 + now.tv_sec * 1000;
		sem_post(philo->last_eat_lock);
	}
	else
	{
		ft_wait_ms_until(philo, philo->state->pi.time_to_die + 1, 0);
		philo->timestamp = philo->state->pi.time_to_die + 1;
	}
	err = do_action(philo, philo->state->pi.time_to_eat, EAT_MSG);
	ph_release_fork(philo);
	ph_release_fork(philo);
	philo->n_meals++;
	return (err);
}
