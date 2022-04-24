/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:12:53 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/24 17:04:01 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
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

static int	init_simulation(t_simulation_state **state, t_philo **philos,
				int ac, char **av)
{
	int	err;

	*state = malloc(sizeof(**state));
	if (!*state)
		return (1);
	err = parse_args_and_print_error(&(*state)->pi, ac, av);
	if (err)
		return (2);
	err = init_philos_with_forks(philos, *state);
	if (err)
		return (err);
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
	err = init_forks(*philos);
	if (err)
	{
		write(2, "An error occured while initializing forks.\n", 43);
		return (4);
	}
	return (err);
}

static void	free_simulation(t_philo	*philos, t_simulation_state *state)
{
	free_forks(philos);
	free(philos);
	free(state);
}
