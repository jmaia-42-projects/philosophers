/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbrlen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:37:00 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/12 17:38:45 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	nbrlen(unsigned long nbr)
{
	int				size;
	unsigned long	tmp_nbr;

	if (nbr == 0)
		return (1);
	size = 0;
	tmp_nbr = nbr;
	while (tmp_nbr != 0)
	{
		tmp_nbr /= 10;
		size++;
	}
	return (size);
}
