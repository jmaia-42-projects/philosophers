/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:13:32 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/23 16:08:32 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions/actions.h"

#include "actions/do_actions.h"

int	ph_eat(t_philo *philo)
{
	if (philo->time_doing_action_x10 == 0)
	{
		do_action(philo, EAT_MSG, 0);
		philo->last_eat = philo->timestamp_x10 / 10;
	}
	if (philo->time_doing_action_x10 / 10 == philo->state->pi.time_to_eat)
	{
		philo->n_meals++;
		return (0);
	}
	return (1);
}
