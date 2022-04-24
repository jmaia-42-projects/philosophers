/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   did_philo_starve_to_death.h                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 19:02:23 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/23 19:07:52 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DID_PHILO_STARVE_TO_DEATH_H
# define DID_PHILO_STARVE_TO_DEATH_H

# include "philo.h"

int	kill_philo_if_he_starve_to_death(t_philo *philo);
int	did_philo_starve_to_death(t_philo *philo);

#endif
