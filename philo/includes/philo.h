/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 10:10:03 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/19 12:53:36 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>

# include "philos_infos.h"

typedef struct s_philo
{
	int					id;
	int					last_eat;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_t			thread;
	t_philos_infos		*pi;
}	t_philo;

#endif
