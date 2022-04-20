/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:06:10 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/20 09:52:15 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

int	start_simulation(t_philo *philos, t_simulation_state *state)
{
	int	i;
	int	err;

	i = 0;
	err = 0;
	while (i < state->pi.n_philos && !err)
	{
		err = pthread_create(&philos[i].thread, 0, &live, &philos[i]);
		i++;
	}
	return (err != 0);
}
