/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:38:00 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/24 20:51:06 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

#include <fcntl.h>
#include <semaphore.h>
#include <stdlib.h>
#include <sys/stat.h>

#include <stdio.h>

int	init_forks(t_simulation_state *state)
{
	state->forks = sem_open("/ph_forks", O_CREAT, 0644, state->pi.n_philos);
	return (0);
}
