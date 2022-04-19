/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:30:28 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/19 12:19:08 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

void	*live(void *param)
{
	int		is_simulation_over; // NEED TO BE REPLACED
	t_philo	*philo;

	philo = (t_philo *)param;
	is_simulation_over = 0;
	while (!is_simulation_over)
	{
		ph_eat(philo);
		ph_sleep(philo);
		ph_think(philo);
	}
	return (0);
}
