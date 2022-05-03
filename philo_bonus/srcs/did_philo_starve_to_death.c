/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   did_philo_starve_to_death.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:01:53 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/03 11:26:44 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "did_philo_starve_to_death.h"

#include "actions/do_actions.h"

int	kill_philo_if_he_starve_to_death(t_philo *philo)
{
	int	i;

	i = 0;
	if (did_philo_starve_to_death(philo))
	{
		sem_wait(philo->state->write_lock);
		print_action(philo->timestamp, philo->id, DIE_MSG);
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
	return (philo->last_eat + philo->state->pi.time_to_die < philo->timestamp);
}
