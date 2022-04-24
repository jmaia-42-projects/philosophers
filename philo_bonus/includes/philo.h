/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 10:10:03 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/24 14:26:39 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# include "fork.h"
# include "philos_infos.h"
# include "simulation_state.h"

typedef struct s_philo
{
	int					id;
	int					pid;
	unsigned long		last_eat;
	int					n_meals;
	t_simulation_state	*state;
	unsigned long		timestamp;
}	t_philo;

#endif
