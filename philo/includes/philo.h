/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 10:10:03 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/23 16:19:50 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# include "actions/actions.h"
# include "fork.h"
# include "philos_infos.h"
# include "simulation_state.h"

typedef struct s_philo
{
	int					id;
	unsigned long		last_eat;
	int					n_meals;
	t_fork				*left_fork;
	t_fork				*right_fork;
	pthread_t			thread;
	t_simulation_state	*state;
	unsigned long		timestamp_x10;
	int					time_doing_action_x10;
	t_actions			cur_action;
}	t_philo;

#endif
