/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:06:10 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/28 20:19:05 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

#include <sys/time.h>
#include <unistd.h>

#include "ft_wait.h"

static void	set_ref_time(void);

int	start_simulation(t_philo *philos, t_simulation_state *state)
{
	int	i;
	int	pid;

	i = 0;
	pid = 0;
	set_ref_time();
	gettimeofday(&state->start, 0);
	while (i < state->pi.n_philos && pid != -1)
	{
		pid = fork();
		if (pid == 0)
		{
			sem_wait(state->start_simulation_lock);
			live(&philos[i]);
			break ;
		}
		else
			philos[i].pid = pid;
		i++;
	}
	i = 0;
	while (pid != 0 && i++ < state->pi.n_philos)
		sem_post(state->start_simulation_lock);
	return (pid);
}

static void	set_ref_time(void)
{
	struct timeval	ref_time;

	gettimeofday(&ref_time, 0);
	ft_wait_ms_until(0, 0, &ref_time);
}
