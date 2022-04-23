/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:54:14 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/23 11:25:55 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions/actions.h"

#include "actions/do_actions.h"

int	ph_take_fork(t_philo *philo, pthread_mutex_t *fork)
{
	int	err;

	pthread_mutex_lock(fork);
	err = do_action(philo, 0, TAKE_FORK_MSG);
	return (err);
}

void	ph_release_fork(pthread_mutex_t *fork)
{
	pthread_mutex_unlock(fork);
}
