/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:54:14 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/23 12:03:00 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions/actions.h"

#include "actions/do_actions.h"
#include "ft_wait.h"
#include "timeval_ops.h"

int	ph_take_fork(t_philo *philo, t_fork *fork)
{
	int				is_fork_taken;
	struct timeval	new_try;
	int				time_waited;

	is_fork_taken = 0;
	time_waited = 0;
	while (!is_fork_taken)
	{
		is_fork_taken = ph_try_to_take_fork(philo, fork);
		if (is_fork_taken == -1)
			return (1);
		if (!is_fork_taken)
		{
			gettimeofday(&new_try, 0);
			new_try = sum(new_try, 500);
			ft_wait_until(new_try, 0);
			time_waited += 500;
			if (time_waited > 1000)
			{
				time_waited = 0;
				philo->timestamp++;
			}
		}
	}
	return (0);
}

int	ph_try_to_take_fork(t_philo *philo, t_fork *fork)
{
	int	err;
	int	is_fork_owned;

	is_fork_owned = 0;
	pthread_mutex_lock(&fork->fork_owner_lock);
	if (!fork->fork_owner)
	{
		fork->fork_owner = philo->id;
		is_fork_owned = 1;
	}
	pthread_mutex_unlock(&fork->fork_owner_lock);
	err = 0;
	if (is_fork_owned)
		err = do_action(philo, 0, TAKE_FORK_MSG);
	if (err)
		return (-1);
	return (is_fork_owned);
}

void	ph_release_fork(t_fork *fork)
{
	pthread_mutex_lock(&fork->fork_owner_lock);
	fork->fork_owner = 0;
	pthread_mutex_unlock(&fork->fork_owner_lock);
}
