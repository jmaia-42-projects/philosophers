/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:30:28 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/03 12:10:03 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

#include <unistd.h>

#include "ft_wait.h"

static int	is_simulation_over(t_philo *philo);
static void	wait_till_next_meal(t_philo *philo);

void	*live(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (!is_simulation_over(philo))
	{
		wait_till_next_meal(philo);
		ph_eat(philo);
		ph_sleep(philo);
		ph_think(philo);
	}
	sem_post(philo->state->end_simulation_lock);
	return (0);
}

static int	is_simulation_over(t_philo *philo)
{
	return (philo->state->pi.n_meals != -1
		&& philo->n_meals >= philo->state->pi.n_meals);
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
