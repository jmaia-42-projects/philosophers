/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:40:25 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/28 23:51:15 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WAIT_H
# define FT_WAIT_H

# include <sys/time.h>
# include "philo.h"

void	ft_wait_ms_until(t_philo *philo, unsigned long wait_time_ms,
			struct timeval *p_ref_time);
void	ft_wait_until(t_philo *philo, struct timeval wait_time,
			struct timeval *p_ref_time);

#endif
