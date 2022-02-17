/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_something.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:40:31 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/17 14:21:51 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "do_something.h"

static void	get_action_desc(char *action_desc, t_action action);

void	do_something(int philo_id, t_action action, t_world *world)
{
	suseconds_t	timestamp;
	char		*action_desc;

	get_action_desc(&action_desc, action);
	timestamp = get_timestamp(world->start_time);
	printf("%ld %d %s\n", timestamp, philo_id, action_desc);
}

static void	get_action_desc(char *action_desc, t_action action)
{
	if (action == FORK)
		*actions_desc = "has taken a fork";
	else if (action == EAT)
		*actions_desc = "is eating";
	else if (action == SLEEP)
		*actions_desc = "is sleeping";
	else if (action == THINK)
		*actions_desc = "is thinking";
	else if (action == DIE)
		*actions_desc = "died";
	else
		*actions_desc = "";
}
