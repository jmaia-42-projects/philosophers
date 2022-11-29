/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:30:28 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/29 12:47:00 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

#include <unistd.h>

#include "ft_wait.h"
#include "did_philo_starve_to_death.h"

static int	is_simulation_over(t_philo *philo);
static void	wait_till_first_meal(t_philo *philo);
static void	init_monitor_thread(t_philo *philo);
static void	*monitor(void *arg);

void	*live(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	wait_till_first_meal(philo);
	init_monitor_thread(philo);
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

	if (philo->state->pi.n_philos == 1)
		first_meal = 0;
	else if (philo->state->pi.n_philos % 2 == 0)
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
	ft_wait_ms_until(philo, first_meal, 0);
	philo->timestamp = first_meal;
}

static void	init_monitor_thread(t_philo *philo)
{
	pthread_t	thread_id;

	pthread_create(&thread_id, 0, monitor, philo);
	pthread_detach(thread_id);
}

static void	*monitor(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *) arg;
	while (1)
	{
		kill_philo_if_he_starve_to_death(philo);
		usleep(1000);
	}
	return (0);
}
