/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_eat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:13:32 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/23 21:22:35 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions/actions.h"

#include "actions/do_actions.h"

#include <stdio.h>

int	ph_eat(t_philo *philo)
{
	int	err;

	ph_take_fork(philo, philo->left_fork);
	ph_take_fork(philo, philo->right_fork);
	philo->last_eat = philo->timestamp;
	err = do_action(philo, philo->state->pi.time_to_eat, EAT_MSG);
	ph_release_fork(philo->left_fork);
	ph_release_fork(philo->right_fork);
	philo->n_meals++;
	return (err);
}
