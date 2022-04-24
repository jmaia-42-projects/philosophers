/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_think.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 12:13:32 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/20 10:36:31 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions/actions.h"

#include "actions/do_actions.h"

int	ph_think(t_philo *philo)
{
	int	err;

	err = do_action(philo, 0, THINK_MSG);
	return (err);
}
