/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:07:48 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/08 17:21:09 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#include "it_is_not_libft_hoho.h"

int	ft_isint(char *nbr)
{
	int		i;
	char	*test_nbr;
	int		is_int;
	int		has_sign;

	has_sign = 0;
	if (!ft_isnbr(nbr))
		return (0);
	i = 0;
	while (ft_isspace(nbr[i]))
		i++;
	if (nbr[i] == '+' || nbr[i] == '-')
	{
		has_sign = 1;
		i++;
	}
	test_nbr = (char *) ft_itoa(ft_atoi(nbr));
	if (!test_nbr)
		return (0);
	if (ft_strcmp(nbr + i - has_sign, test_nbr))
		is_int = 0;
	else
		is_int = 1;
	free(test_nbr);
	return (is_int);
}
