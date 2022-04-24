/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:26:54 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/24 23:39:49 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

#include <stdlib.h>

static void	init_philo(t_philo *philo, int id, t_simulation_state *state);

int	init_philos(t_philo **philos, t_simulation_state *state)
{
	int	i;

	i = 0;
	*philos = malloc(sizeof(**philos) * state->pi.n_philos);
	if (!*philos)
		return (1);
	while (i < state->pi.n_philos)
	{
		init_philo(&(*philos)[i], i + 1, state);
		i++;
	}
	return (0);
}

static void	init_philo(t_philo *philo, int id, t_simulation_state *state)
{
	philo->id = id;
	philo->last_eat = -1;
	philo->left_fork = 0;
	philo->right_fork = 0;
	philo->n_meals = 0;
	philo->state = state;
	philo->timestamp = 0;
}
