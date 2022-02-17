/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 17:24:36 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/17 15:30:15 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "live.h"

static void	parse_param(void *param, t_world **world, int *philo_id);
static void	philo_eat(int philo_id, t_world *world);
static void	philo_think(int philo_id, t_world *world);
static void	philo_sleep(int philo_id, t_world *world);

void	*live(void *param)
{
	t_world	*world;
	int		philo_id;

	parse_param(param, &world, &philo_id);
	philo_eat(philo_id, world);
	philo_think(philo_id, world);
	philo_sleep(philo_id, world);
	return (0);
}

static void	parse_param(void *param, t_world **world, int *philo_id)
{
	void	**params;

	params = (void **)param;
	*world = (t_world *)params[0];
	*philo_id = *(int *)params[1];
}

static void	philo_eat(int philo_id, t_world *world)
{
	do_something(philo_id, EAT, world);
}

static void	philo_think(int philo_id, t_world *world)
{
	do_something(philo_id, THINK, world);
}

static void	philo_sleep(int philo_id, t_world *world)
{
	do_something(philo_id, SLEEP, world);
}
