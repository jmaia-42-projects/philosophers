/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_actions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:07:45 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/28 22:21:17 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_ACTIONS_H
# define DO_ACTIONS_H

# include "actions.h"

int	do_action(t_philo *philo, unsigned long duration, char *action);
int	print_action(unsigned long timestamp, unsigned int philo_i,
		char *action);

#endif
