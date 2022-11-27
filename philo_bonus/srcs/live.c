/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:30:28 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/27 20:15:40 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

#include <unistd.h>

#include "ft_wait.h"

static int	is_simulation_over(t_philo *philo);
static void	wait_till_first_meal(t_philo *philo);

void	*live(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	wait_till_first_meal(philo);
	while (!is_simulation_over(philo))
	{
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

static void	wait_till_first_meal(t_philo *philo)
{
	unsigned long	first_meal;

	if (philo->state->pi.n_philos % 2 == 0)
	{
		if (philo->id % 2 == 0)
			first_meal = 0;
		else
			first_meal = philo->state->pi.time_to_eat - 10;
	}
	else
	{
		if (philo->id % 3)
			first_meal = philo->id % 3 * philo->state->pi.time_to_eat - 10;
		else
			first_meal = 0;
	}
	ft_wait_ms_until(first_meal, 0);
	philo->timestamp = first_meal;
}
