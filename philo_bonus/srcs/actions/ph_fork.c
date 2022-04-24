/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:54:14 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/24 20:55:22 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions/actions.h"

#include <semaphore.h>

#include "actions/do_actions.h"

int	ph_take_fork(t_philo *philo)
{
	sem_wait(philo->state->forks);
	do_action(philo, 0, TAKE_FORK_MSG);
	return (0);
}

void	ph_release_fork(t_philo *philo)
{
	sem_post(philo->state->forks);
}
