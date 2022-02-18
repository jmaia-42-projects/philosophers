/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:19:51 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/18 12:41:15 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophize.h"

static int		give_birth_to_philos(t_world *world);
static void		kill_philos(t_philo *philos, int n);

int	philosophize(t_philos_infos	*pi)
{
	t_world	*world;
	int		err;

	world = new_world(pi);
	if (!world)
		return (1);
	err = give_birth_to_philos(world);
	if (err)
	{
		destroy_world(world);
		return (1);
	}
	while (1)
		;
	return (0);
}

static int	give_birth_to_philos(t_world *world)
{
	int		i;
	int		err;
	void	*params[2];

	i = 0;
	params[0] = world;
	err = 0;
	while (i < world->pi->n_philos && !err)
	{
		world->philos[i].last_meal = 0;
		world->philos[i].n_meals = 0;
		params[1] = malloc(sizeof(int));
		if (!params[1])
		{
			kill_philos(world->philos, i);
			return (1);
		}
		*(int *)params[1] = i;
		err = pthread_create(&world->philos[i].thread, 0, &live, params);
		if (err)
			kill_philos(world->philos, i);
		i++;
	}
	return (err);
}

static void	kill_philos(t_philo *philos, int n)
{
	(void) philos;
	(void) n;
}
