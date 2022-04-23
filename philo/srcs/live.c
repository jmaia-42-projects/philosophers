/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 11:30:28 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/23 15:24:52 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

#include <sys/time.h>

#include "actions/ph_actions.h"
#include "ft_wait.h"

static int			is_simulation_over(t_philo *philo);
static void			do_action_turn(t_philo *philo, int (*action)(t_philo *));
static void			wait_until_next_turn(t_philo *philo);
static t_actions	get_next_action(t_actions action);

void	*live(void *param)
{
	t_philo	*philo;

	philo = (t_philo *)param;
	while (!is_simulation_over(philo))
	{
		if (philo->cur_action == TAKE_FORK_1)
			do_action_turn(philo, &ph_take_fork);
		if (philo->cur_action == TAKE_FORK_2)
			do_action_turn(philo, &ph_take_fork);
		if (philo->cur_action == EAT)
			do_action_turn(philo, &ph_eat);
		if (philo->cur_action == RELEASE_FORK_2)
			do_action_turn(philo, &ph_release_fork);
		if (philo->cur_action == RELEASE_FORK_1)
			do_action_turn(philo, &ph_release_fork);
		if (philo->cur_action == SLEEP)
			do_action_turn(philo, &ph_sleep);
		if (philo->cur_action == THINK)
			do_action_turn(philo, &ph_think);
		wait_until_next_turn(philo);
	}
	return (0);
}

static int	is_simulation_over(t_philo *philo)
{
	int	is_simulation_over;

	if (philo->state->pi.n_meals != -1
		&& philo->n_meals >= philo->state->pi.n_meals)
		return (1);
	pthread_mutex_lock(&philo->state->is_simulation_over_lock);
	is_simulation_over = philo->state->is_simulation_over;
	pthread_mutex_unlock(&philo->state->is_simulation_over_lock);
	return (is_simulation_over);
}

static void	do_action_turn(t_philo *philo, int (*action)(t_philo *))
{
	int	is_action_end;

	is_action_end = !action(philo);
	if (is_action_end)
	{
		philo->cur_action = get_next_action(philo->cur_action);
		philo->time_doing_action_x10 = 0;
		philo->timestamp_x10 = philo->timestamp_x10 / 10 * 10;
	}
}

static t_actions	get_next_action(t_actions action)
{
	if (action == TAKE_FORK_1)
		return (TAKE_FORK_2);
	if (action == TAKE_FORK_2)
		return (EAT);
	if (action == EAT)
		return (RELEASE_FORK_2);
	if (action == RELEASE_FORK_2)
		return (RELEASE_FORK_1);
	if (action == RELEASE_FORK_1)
		return (SLEEP);
	if (action == SLEEP)
		return (THINK);
	return (TAKE_FORK_1);
}

static void	wait_until_next_turn(t_philo *philo)
{
	struct timeval	time_point;

	philo->timestamp_x10 += 5;
	time_point.tv_sec = philo->timestamp_x10 / 10000;
	time_point.tv_usec = philo->timestamp_x10 % 10000 * 100;
	ft_wait_until(time_point, 0);
	philo->time_doing_action_x10 += 5;
}
