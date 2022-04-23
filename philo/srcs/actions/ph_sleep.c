/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_sleep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:13:32 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/23 15:24:18 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions/actions.h"

#include "actions/do_actions.h"

int	ph_sleep(t_philo *philo)
{
	if (philo->time_doing_action_x10 == 0)
		do_action(philo, SLEEP_MSG);
	if (philo->time_doing_action_x10 / 10 == philo->state->pi.time_to_sleep)
		return (0);
	return (1);
}
