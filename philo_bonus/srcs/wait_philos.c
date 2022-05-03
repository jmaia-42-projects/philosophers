/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:43:39 by jmaia             #+#    #+#             */
/*   Updated: 2022/05/03 11:48:02 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

#include <signal.h>

void	wait_philos(t_philo *philos, t_simulation_state *state)
{
	int	i;

	i = 0;
	while (i < state->pi.n_philos)
	{
		sem_wait(state->end_simulation_lock);
		i++;
	}
	i = 0;
	while (i < state->pi.n_philos)
	{
		kill(philos[i].pid, 15);
		i++;
	}
}
