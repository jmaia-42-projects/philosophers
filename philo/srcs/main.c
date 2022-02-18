/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 12:47:04 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/18 11:18:59 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include  "it_is_not_libft_hoho.h"

#include "parse_args.h"
#include "philosophize.h"

static void	print_syntax(const char *prog_name);

int	main(int ac, char **av)
{
	t_philos_infos	*pi;
	int				err;

	pi = parse_args(ac, av);
	if (!pi)
	{
		print_syntax(av[0]);
		return (1);
	}
	err = philosophize(pi);
	if (err)
	{
		write(2, "An error occured while philosophizing\n", 38);
		return (1);
	}
	return (0);
}

static void	print_syntax(const char *prog_name)
{
	write(2, prog_name, ft_strlen(prog_name));
	write(2,
		" <number_of_philosophers> <time_to_die> <time_to_eat>"
		" <time_to_sleep> [number_of_meals]\n", 88);
}
