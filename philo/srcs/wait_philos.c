/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:43:39 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/20 09:50:38 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

void	wait_philos(t_philo *philos, t_simulation_state *state)
{
	int	i;

	i = 0;
	while (i < state->pi.n_philos)
	{
		pthread_join(philos[i].thread, 0);
		i++;
	}
}
