/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 12:17:38 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/18 12:41:20 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WORLD_H
# define WORLD_H

# include <stdlib.h>
# include <sys/time.h>

# include "philos_infos.h"

typedef struct s_world
{
	t_philos_infos	*pi;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	struct timeval	*start_time;
}	t_world;

t_world	*new_world(t_philos_infos *pi);
void	destroy_world(t_world *world);

#endif
