/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:38:00 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/24 17:02:59 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

#include <fcntl.h>
#include <semaphore.h>
#include <stdlib.h>
#include <sys/stat.h>

int	init_forks(t_philo *philos)
{
	sem_open("ph_forks", O_CREAT, O_RDWR, philos->state->pi.n_philos);
	return (0);
}
