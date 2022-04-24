/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:06:10 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/24 18:47:00 by jmaia            ###   ########.fr       */
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
	set_ref_time();
	pid = 0;
	while (i < state->pi.n_philos && pid != -1)
	{
		pid = fork();
		if (pid == 0)
		{
			live(&philos[i]);
			break;
		}
		else
			philos[i].pid = pid;
		i++;
	}
	return (pid == -1);
}

static void	set_ref_time(void)
{
	struct timeval	ref_time;

	gettimeofday(&ref_time, 0);
	ft_wait_ms_until(0, &ref_time);
}
