/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:30:28 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/20 10:12:02 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

static int	is_simulation_over(t_philo *philo);

void	*live(void *param)
{
	int		is_simulation_over; // NEED TO BE REPLACED
	t_philo	*philo;

	philo = (t_philo *)param;
	is_simulation_over = 0;
	while (!is_simulation_over)
	{
		ph_eat(philo);
		ph_sleep(philo);
		ph_think(philo);
	}
	return (0);
}

static int	is_simulation_over(t_philo *philo)
{
	int	is_simulation_over;

	if (philo->n_meals >= philo->state->pi.n_meals)
		return (1);
	pthread_mutex_lock(&philo->state->is_simulation_over_lock);
	is_simulation_over = philo->state->is_simulation_over;
	pthread_mutex_unlock(&philo->state->is_simulation_over_lock);
	return (is_simulation_over);
}
