/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:30:28 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/24 23:39:30 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

#include "ft_wait.h"

static int	is_simulation_over(t_philo *philo);
static void	delay_start(t_philo *philo);
static void	wait_till_next_meal(t_philo *philo);

void	*live(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	delay_start(philo);
	while (!is_simulation_over(philo))
	{
		wait_till_next_meal(philo);
		ph_eat(philo);
		ph_sleep(philo);
		ph_think(philo);
	}
	return (0);
}

static void	delay_start(t_philo *philo)
{
	if (!(philo->id % 2))
	{
		philo->timestamp += philo->state->pi.time_to_eat / 2;
		ft_wait_ms_until(philo->timestamp, 0);
	}
}

static int	is_simulation_over(t_philo *philo)
{
	int	is_simulation_over;

	if (philo->state->pi.n_meals != -1
		&& philo->n_meals >= philo->state->pi.n_meals)
		return (1);
	pthread_mutex_lock(&philo->state->is_simulation_over_lock);
	is_simulation_over = philo->state->is_simulation_over;
	pthread_mutex_unlock(&philo->state->is_simulation_over_lock);
	return (is_simulation_over);
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
