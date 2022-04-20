/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:06:12 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/20 11:00:39 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# define TAKE_FORK_MSG	"has taken a fork"
# define EAT_MSG		"is eating"
# define SLEEP_MSG		"is sleeping"
# define THINK_MSG		"is thinking"
# define DIE_MSG		"died"

# include "philo.h"

typedef enum e_actions
{
	TAKE_FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}	t_actions;

int		ph_eat(t_philo *philo);
int		ph_sleep(t_philo *philo);
int		ph_take_fork(t_philo *philo, pthread_mutex_t *fork);
void	ph_release_fork(pthread_mutex_t *fork);
int		ph_think(t_philo *philo);

#endif
