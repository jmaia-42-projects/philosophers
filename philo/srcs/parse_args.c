/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:45:27 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/08 17:06:45 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_args.h"

static int	are_args_valid(int ac, char **av);

t_philos_infos	parse_args(int ac, char **av)
{
	t_philos_infos	pi;

	if (!are_args_valid(ac, av))
	{
		pi.n_philos = -1;
		return (pi);
	}
	pi.n_philos = ft_atoi(av[1]);
	pi.time_to_die = ft_atoi(av[2]);
	pi.time_to_eat = ft_atoi(av[3]);
	pi.time_to_sleep = ft_atoi(av[4]);
	if (ac > 5)
		pi.n_meals = ft_atoi(av[5]);
	return (pi);
}

static int	are_args_valid(int ac, char **av)
{
	int	i;

	if (ac < 5)
		return (0);
	i = 1;
	while (i < 5)
	{
		if (!ft_isint(av[i]))
			return (0);
		i++;
	}
	return (ac == 5 || ft_isint(av[5]));
}
