/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:38:31 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/18 20:36:27 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "philo.h"
# include "philos_infos.h"

int		init_forks(t_philo *philos, t_philos_infos *pi);
int		init_philos(t_philo **philos, t_philos_infos *pi);
int		start_simulation(t_philo *philos, t_philos_infos *pi);
void	free_forks(t_philo *philos);
void	wait_philos(t_philo *philos, t_philos_infos *pi);

#endif
