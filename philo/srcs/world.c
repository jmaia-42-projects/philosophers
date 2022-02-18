/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 10:24:43 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/18 12:27:27 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "world.h"

t_world	*new_world(t_philos_infos *pi)
{
	t_world	*world;

	world = malloc(sizeof(*world));
	if (!world)
		return (0);
	world->pi = pi;
	world->philos = malloc(sizeof(*world->philos) * pi->n_philos);
	world->forks = malloc(sizeof(*world->forks) * pi->n_philos);
	world->start_time = malloc(sizeof(*world->start_time));
	if (!world->philos || !world->forks || !world->start_time)
	{
		destroy_world(world);
		return (0);
	}
	gettimeofday(world->start_time, 0);
	return (world);
}

void	destroy_world(t_world *world)
{
	if (!world)
		return ;
	if (world->philos)
		free(world->philos);
	if (world->forks)
		free(world->forks);
	if (world->start_time)
		free(world->start_time);
}
