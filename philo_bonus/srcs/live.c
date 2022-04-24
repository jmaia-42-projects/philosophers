/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:30:28 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/24 17:03:38 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

#include "ft_wait.h"

static void	delay_start(t_philo *philo);

void	*live(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	delay_start(philo);
	while (1)
	{
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
