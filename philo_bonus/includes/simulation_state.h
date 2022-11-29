/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_state.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:39:16 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/28 15:55:19 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_STATE_H
# define SIMULATION_STATE_H

# include <semaphore.h>

typedef struct s_simulation_state
{
	sem_t			*write_lock;
	sem_t			*forks;
	sem_t			*end_simulation_lock;
	sem_t			*start_simulation_lock;
	t_philos_infos	pi;
	struct timeval	start;
}	t_simulation_state;

#endif
