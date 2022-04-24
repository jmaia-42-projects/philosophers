/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:54:14 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/24 22:13:04 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions/actions.h"

#include <semaphore.h>
#include <sys/time.h>

#include "actions/do_actions.h"
#include "timeval_ops.h"

int	ph_take_fork(t_philo *philo)
{
	struct timeval	after;
	struct timeval	before;
	struct timeval	diff;

	gettimeofday(&before, 0);
	sem_wait(philo->state->forks);
	gettimeofday(&after, 0);
	diff = time_diff(after, before);
	if (diff.tv_sec > 0 || diff.tv_usec > 200)
		philo->timestamp += philo->state->pi.time_to_eat;
	do_action(philo, 0, TAKE_FORK_MSG);
	return (0);
}

void	ph_release_fork(t_philo *philo)
{
	sem_post(philo->state->forks);
}
