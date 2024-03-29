/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:12:53 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/28 19:17:50 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <signal.h>
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
	int					fork_state;
	t_philo				*philos;
	t_simulation_state	*state;
	int					i;

	err = init_simulation(&state, &philos, ac, av);
	if (err)
		return (err);
	fork_state = start_simulation(philos, state);
	if (fork_state == -1)
		write(2, "An error occured during simulation.\n", 36);
	i = 0;
	if (fork_state != 0)
		while (i++ < state->pi.n_philos)
			sem_wait(state->end_simulation_lock);
	i = -1;
	while (++i < state->pi.n_philos)
		kill(philos[i].pid, 15);
	free_simulation(philos, state);
}

static int	init_simulation(t_simulation_state **state, t_philo **philos,
				int ac, char **av)
{
	int	err;

	*state = malloc(sizeof(**state));
	if (!*state)
		return (1);
	close_sems();
	err = parse_args_and_print_error(&(*state)->pi, ac, av);
	if (err)
		return (2);
	err = init_philos_with_forks(philos, *state);
	if (err)
		return (err);
	(*state)->end_simulation_lock = sem_open("/ph_end_simulation_lock",
			O_CREAT, 0644, 0);
	(*state)->start_simulation_lock = sem_open("/ph_start_simulation_lock",
			O_CREAT, 0644, 0);
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
	sem_unlink("/ph_start_simulation_lock");
	sem_unlink("/ph_forks");
	sem_unlink("/ph_write_lock");
}
