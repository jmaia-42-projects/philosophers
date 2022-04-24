/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:30:28 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/24 23:07:10 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

#include "ft_wait.h"

static void	wait_till_next_meal(t_philo *philo);

//#include <stdio.h>

void	*live(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (1)
	{
//		struct timeval now;

//		gettimeofday(&now, 0);
//		printf("Let's %d try now (%ld, %ld)\n", philo->id,  now.tv_sec, now.tv_usec);
		ph_eat(philo);
		ph_sleep(philo);
		ph_think(philo);
		wait_till_next_meal(philo);
	}
	return (0);
}

static void	wait_till_next_meal(t_philo *philo)
{
	unsigned long	next_meal;

	if (philo->state->pi.n_philos % 2 != 1)
		return ;
	next_meal = philo->last_eat + 3 * philo->state->pi.time_to_eat;
	ft_wait_ms_until(next_meal - 10, 0);
	philo->timestamp = next_meal - 10;
}
