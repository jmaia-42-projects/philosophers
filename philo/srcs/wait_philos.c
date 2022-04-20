/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:43:39 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/20 09:30:08 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

void	wait_philos(t_philo *philos, t_philos_infos *pi)
{
	int	i;

	i = 0;
	while (i < pi->n_philos)
	{
		pthread_join(philos[i].thread, 0);
		i++;
	}
}
