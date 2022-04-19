/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:12:53 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/19 11:12:18 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "parse_args.h"
#include "philo.h"
#include "philos_infos.h"
#include "simulation.h"

static int	init_simulation(t_philos_infos **pi, t_philo **philos,
				int ac, char **av);
static void	free_simulation(t_philo *philos, t_philos_infos *pi);

int	main(int ac, char **av)
{
	int				err;
	t_philo			*philos;
	t_philos_infos	*pi;

	err = init_simulation(&pi, &philos, ac, av);
	if (err)
		return (err);
	err = start_simulation(philos, pi);
	if (err)
		write(2, "An error occured during simulation.\n", 36);
	wait_philos(philos, pi);
	free_simulation(philos, pi);
}

static int	init_simulation(t_philos_infos **pi, t_philo **philos,
				int ac, char **av)
{
	int	err;

	err = parse_args_and_print_error(pi, ac, av);
	if (err)
		return (1);
	err = init_philos(philos, *pi);
	if (err)
	{
		write(2, "An error occured while initializing philos.\n", 44);
		return (2);
	}
	err = init_forks(*philos, *pi);
	if (err)
	{
		write(2, "An error occured while initializing forks.\n", 43);
		return (3);
	}
	return (0);
}

static void	free_simulation(t_philo	*philos, t_philos_infos *pi)
{
	free_forks(philos);
	free(philos);
	free(pi);
}
