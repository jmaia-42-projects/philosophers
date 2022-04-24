/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:38:31 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/24 17:02:21 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "actions/actions.h"
# include "philo.h"
# include "philos_infos.h"
# include "simulation_state.h"

int		init_forks(t_philo *philos);
int		init_philos(t_philo **philos, t_simulation_state *state);
int		start_simulation(t_philo *philos, t_simulation_state *state);
void	*live(void *param);
void	free_forks(t_philo *philos);
void	wait_philos(t_philo *philos, t_simulation_state *state);

#endif
