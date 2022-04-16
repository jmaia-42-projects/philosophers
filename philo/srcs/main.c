/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 18:12:53 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/16 10:06:24 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

#include "philos_infos.h"
#include "parse_args.h"

int	main(int ac, char **av)
{
	t_philos_infos	pi;

	parse_args(&pi, ac, av);
	if (pi.n_philos == -1)
	{
		write(2, "An error occured while parsing arguments.\n", 42);
		return (1);
	}
}
