/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 19:38:31 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/19 11:28:09 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include "philo.h"
# include "philos_infos.h"

int		init_forks(t_philo *philos, t_philos_infos *pi);
int		init_philos(t_philo **philos, t_philos_infos *pi);
int		start_simulation(t_philo *philos, t_philos_infos *pi);
void	*live(void *param);
void	free_forks(t_philo *philos);
void	wait_philos(t_philo *philos, t_philos_infos *pi);

#endif
