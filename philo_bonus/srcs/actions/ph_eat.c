/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:13:32 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/24 22:42:59 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions/actions.h"

#include "actions/do_actions.h"
#include "ft_wait.h"

int	ph_eat(t_philo *philo)
{
	int	err;

	ph_take_fork(philo);
	if (philo->state->pi.n_philos > 1)
	{
		ph_take_fork(philo);
		philo->last_eat = philo->timestamp;
	}
	else
	{
		ft_wait_ms_until(philo->state->pi.time_to_die + 1, 0);
		philo->timestamp = philo->state->pi.time_to_die + 1;
	}
	err = do_action(philo, philo->state->pi.time_to_eat, EAT_MSG);
	ph_release_fork(philo);
	ph_release_fork(philo);
	philo->n_meals++;
	return (err);
}
