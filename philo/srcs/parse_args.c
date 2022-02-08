/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:45:27 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/08 14:48:23 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parse_args.h"

t_philos_infos	parse_args(int ac, char **av)
{
	t_philos_infos	pi;

	pi.n_philos = -1;
	(void) ac;
	(void) av;
	return (pi);
}
