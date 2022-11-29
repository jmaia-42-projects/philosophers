/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:06:10 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/28 22:32:31 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

#include <sys/time.h>

#include "ft_wait.h"

static void	set_ref_time(void);

int	start_simulation(t_philo *philos, t_simulation_state *state)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	set_ref_time();
	gettimeofday(&state->start, 0);
	while (i < state->pi.n_philos && !err)
	{
		err = pthread_create(&philos[i].thread, 0, &live, &philos[i]);
		i++;
	}
	return (err != 0);
}

static void	set_ref_time(void)
{
	struct timeval	ref_time;

	gettimeofday(&ref_time, 0);
	ft_wait_ms_until(0, 0, &ref_time);
}
