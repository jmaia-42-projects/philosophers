/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:54:14 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/24 16:48:56 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions/actions.h"

#include <semaphore.h>

int	ph_take_fork(t_philo *philo)
{
	sem_wait(philo->state->forks);
	return (0);
}

void	ph_release_fork(t_philo *philo)
{
	sem_post(philo->state->forks);
}
