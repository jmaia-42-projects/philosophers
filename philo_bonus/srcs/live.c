/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:30:28 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/24 22:31:15 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

#include "ft_wait.h"

static void	wait_till_near_death(t_philo *philo);

void	*live(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (1)
	{
		ph_eat(philo);
		ph_sleep(philo);
		ph_think(philo);
		wait_till_near_death(philo);
	}
	return (0);
}

static void	wait_till_near_death(t_philo *philo)
{
	unsigned long	die_time;

	die_time = philo->last_eat + philo->state->pi.time_to_die;
	ft_wait_ms_until(die_time - 10, 0);
	philo->timestamp = die_time - 10;
}
