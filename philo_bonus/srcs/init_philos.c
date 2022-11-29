/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philos.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 20:26:54 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/28 21:40:36 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <sys/stat.h>
#include <semaphore.h>

#include "simulation.h"
#include "it_is_not_libft_hoho.h"

#include <stdlib.h>

static void	init_philo(t_philo *philo, int id, t_simulation_state *state);
static char	*get_name(int id, char *name);

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
	char	name[100];

	philo->id = id;
	philo->last_eat = 0;
	philo->n_meals = 0;
	philo->state = state;
	philo->timestamp = 0;
	philo->last_eat_lock = sem_open(get_name(id, name), O_CREAT, 0644, 1);
}

static char	*get_name(int id, char *name)
{
	static const char	*base_name = "/philo";
	int					i;

	i = -1;
	while (++i < (int) ft_strlen(base_name))
		name[i] = base_name[i];
	name[i] = (id - 1) % 26 + 65;
	name[i + 1] = (id - 1) / 26 + 65;
	name[i + 2] = 0;
	return (name);
}
