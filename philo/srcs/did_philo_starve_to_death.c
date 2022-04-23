/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   did_philo_starve_to_death.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:01:53 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/23 22:34:55 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "did_philo_starve_to_death.h"

#include "actions/do_actions.h"

int	kill_philo_if_he_starve_to_death(t_philo *philo)
{
	if (did_philo_starve_to_death(philo))
	{
		pthread_mutex_lock(&philo->state->is_simulation_over_lock);
		if (!philo->state->is_simulation_over)
			print_action(philo->timestamp, philo->id, DIE_MSG);
		philo->state->is_simulation_over = 0;
		pthread_mutex_unlock(&philo->state->is_simulation_over_lock);
		return (0);
	}
	return (1);
}

int	did_philo_starve_to_death(t_philo *philo)
{
	return (philo->last_eat + philo->state->pi.time_to_die < philo->timestamp);
}
