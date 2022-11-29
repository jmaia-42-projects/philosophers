/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_state.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:39:16 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/28 22:21:43 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_STATE_H
# define SIMULATION_STATE_H

# include <sys/time.h>

typedef struct s_simulation_state
{
	int				is_simulation_over;
	pthread_mutex_t	is_simulation_over_lock;
	t_philos_infos	pi;
	struct timeval	start;
}	t_simulation_state;

#endif
