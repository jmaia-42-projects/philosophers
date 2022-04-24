/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:13:32 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/24 16:48:40 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions/actions.h"

#include "actions/do_actions.h"

#include <stdio.h>

int	ph_eat(t_philo *philo)
{
	int	err;

	ph_take_fork(philo);
	ph_take_fork(philo);
	philo->last_eat = philo->timestamp;
	err = do_action(philo, philo->state->pi.time_to_eat, EAT_MSG);
	ph_release_fork(philo);
	ph_release_fork(philo);
	philo->n_meals++;
	return (err);
}
