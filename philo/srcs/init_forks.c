/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_forks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:38:00 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/23 11:47:44 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

#include <stdlib.h>

static int		give_fork_to_philos(t_philo *left_philo,
					t_philo *right_philo);
static t_fork	*init_fork(void);

int	init_forks(t_philo *philos, t_philos_infos *pi)
{
	int				err;
	int				i;
	t_philo			*left_philo;

	i = 0;
	err = 0;
	left_philo = 0;
	while (i < pi->n_philos && !err)
	{
		if (i == 0 && pi->n_philos > 1)
			left_philo = &philos[pi->n_philos - 1];
		else if (pi->n_philos > 1)
			left_philo = &philos[i - 1];
		err = give_fork_to_philos(left_philo, &philos[i]);
		i++;
	}
	// USE YOUR MIND
	return (0);
}

static int	give_fork_to_philos(t_philo *left_philo, t_philo *right_philo)
{
	right_philo->left_fork = init_fork();
	if (!right_philo->left_fork)
		return (1);
	if (left_philo)
		left_philo->right_fork = right_philo->left_fork;
	return (0);
}

static t_fork	*init_fork(void)
{
	int				err;
	t_fork			*fork;

	fork = malloc(sizeof(*fork));
	if (!fork)
		return (0);
	fork->fork_owner = 0;
	err = pthread_mutex_init(&fork->fork_owner_lock, 0);
	if (err)
	{
		free(fork);
		return (0);
	}
	return (fork);
}
