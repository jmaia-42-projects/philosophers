/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:19:51 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/14 16:31:07 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophize.h"

static t_philo	*give_birth_to_philos(t_philos_infos *pi);
static void		kill_philos(t_philos *philos, int n);

int	philosophize(t_philos_infos	pi)
{
	t_philo	*phlos;

	philos = give_birth_to_philos(pi);
	if (!philos)
		return (1);
	return (0);
}

static t_philo	*give_birth_to_philos(t_philos_infos *pi)
{
	int		i;
	t_philo	*philos;
	int		err;

	philos = malloc(sizeof(*philos) * pi->n_philos);
	if (!philos)
		return (0);
	i = 0;
	while (i < pi->n_philos)
	{
		err = pthread_create(&philos[i], 0, &live, 0);
		if (err)
			kill_philos(philos, i);
		i++;
	}
	return (philos);
}

static void	kill_philos(t_philos *philos, int n)
{
	(void) philos;
	(void) n;
}
