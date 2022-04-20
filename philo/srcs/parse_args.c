/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:45:27 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/20 09:47:51 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_args.h"

#include <unistd.h>

static int	are_args_valid(int ac, char **av);

int	parse_args_and_print_error(t_philos_infos *pi, int ac, char **av)
{
	int	err;

	err = parse_args(pi, ac, av);
	if (err)
		write(2, "An error occured while parsing arguments.\n", 42);
	return (err);
}

int	parse_args(t_philos_infos *pi, int ac, char **av)
{
	if (!are_args_valid(ac, av))
		return (1);
	pi->n_philos = ft_atoi(av[1]);
	pi->time_to_die = ft_atoi(av[2]);
	pi->time_to_eat = ft_atoi(av[3]);
	pi->time_to_sleep = ft_atoi(av[4]);
	if (ac > 5)
		pi->n_meals = ft_atoi(av[5]);
	return (0);
}

static int	are_args_valid(int ac, char **av)
{
	int	i;

	if (ac < 5)
		return (0);
	i = 1;
	while (i < 5)
	{
		if (!ft_isint(av[i]) || ft_atoi(av[i]) < 0)
			return (0);
		i++;
	}
	return (ac == 5 || ft_isint(av[5]));
}
