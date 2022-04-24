/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:45:47 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/24 15:22:38 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

#include <stdlib.h>

void	free_forks(t_philo *philos)
{
	int	i;

	i = 0;
	while (i < philos[0].state->pi.n_philos)
	{
		free(philos[i].left_fork);
		i++;
	}
}
