/*************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:12:53 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/24 20:56:59 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#include "parse_args.h"
#include "philo.h"
#include "philos_infos.h"
#include "simulation.h"
#include "simulation_state.h"

static int	init_simulation(t_simulation_state **state, t_philo **philos,
				int ac, char **av);
static int	init_philos_with_forks(t_philo **philos, t_simulation_state *state);
static void	free_simulation(t_philo *philos, t_simulation_state *state);
static void	close_sems(void);

int	main(int ac, char **av)
{
	int					err;
	t_philo				*philos;
	t_simulation_state	*state;

	err = init_simulation(&state, &philos, ac, av);
	if (err)
		return (err);
	err = start_simulation(philos, state);
	if (err)
		write(2, "An error occured during simulation.\n", 36);
	wait_philos(philos, state);
	free_simulation(philos, state);
}

#include <stdio.h>

static int	init_simulation(t_simulation_state **state, t_philo **philos,
				int ac, char **av)
{
	int	err;

	close_sems();
	*state = malloc(sizeof(**state));
	if (!*state)
		return (1);
	err = parse_args_and_print_error(&(*state)->pi, ac, av);
	if (err)
		return (2);
	err = init_philos_with_forks(philos, *state);
	if (err)
		return (err);
	(*state)->end_simulation_lock = sem_open("/ph_end_simulation_lock", O_CREAT, 0644, 0);
	return (0);
}

static int	init_philos_with_forks(t_philo **philos, t_simulation_state *state)
{
	int	err;

	err = init_philos(philos, state);
	if (err)
	{
		write(2, "An error occured while initializing philos.\n", 44);
		return (3);
	}
	err = init_forks(state);
	if (err)
	{
		write(2, "An error occured while initializing forks.\n", 43);
		return (4);
	}
	state->write_lock = sem_open("/ph_write_lock", O_CREAT, 0644, 1);
	return (err);
}

static void	free_simulation(t_philo	*philos, t_simulation_state *state)
{
	close_sems();
	free_forks(philos);
	free(philos);
	free(state);
}

static void	close_sems(void)
{
	sem_unlink("/ph_end_simulation_lock");
	sem_unlink("/ph_forks");
	sem_unlink("/ph_write_lock");
}

