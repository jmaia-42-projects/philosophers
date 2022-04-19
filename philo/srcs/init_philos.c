/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:26:54 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/18 21:04:44 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

#include <stdlib.h>

static void	init_philo(t_philo *philo, int id);

int	init_philos(t_philo **philos, t_philos_infos *pi)
{
	int	i;

	i = 0;
	*philos = malloc(sizeof(**philos) * pi->n_philos);
	if (!*philos)
		return (1);
	while (i < pi->n_philos)
	{
		init_philo(&(*philos)[i], i + 1);
		i++;
	}
	return (0);
}

static void	init_philo(t_philo *philo, int id)
{
	philo->id = id;
	philo->last_eat = 0;
	philo->left_fork = 0;
	philo->right_fork = 0;
}
