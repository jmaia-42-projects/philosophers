/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:30:28 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/24 23:29:11 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

#include "ft_wait.h"

static void	wait_till_next_meal(t_philo *philo);

void	*live(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (1)
	{
		wait_till_next_meal(philo);
		ph_eat(philo);
		ph_sleep(philo);
		ph_think(philo);
	}
	return (0);
}

static void	wait_till_next_meal(t_philo *philo)
{
	unsigned long	next_meal;

	if (philo->state->pi.n_philos % 2 != 1)
	{
		if (philo->last_eat == (unsigned long) -1)
			philo->last_eat = 0;
		return ;
	}
	if (philo->last_eat == (unsigned long) -1)
	{
		if (philo->id == philo->state->pi.n_philos)
			next_meal = 0;
		else if (philo->id % 2 == 0)
			next_meal = philo->state->pi.time_to_eat;
		else
			next_meal = philo->state->pi.time_to_eat * 2;
	}
	else
		next_meal = philo->last_eat + 3 * philo->state->pi.time_to_eat;
	ft_wait_ms_until(next_meal, 0);
	philo->timestamp = next_meal;
}
