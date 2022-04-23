/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ph_actions.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 14:49:42 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/23 14:55:59 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PH_ACTIONS_H
# define PH_ACTIONS_H

# include "fork.h"
# include "philo.h"

int	ph_eat(t_philo *philo);
int	ph_sleep(t_philo *philo);
int	ph_take_fork(t_philo *philo);
int	ph_try_to_take_fork(t_philo *philo, t_fork *fork);
int	ph_release_fork(t_philo *philo);
int	ph_think(t_philo *philo);

#endif
