/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 18:28:20 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/08 17:04:34 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

#include "it_is_not_libft_hoho.h"

int	ft_strcmp(char *s1, char *s2)
{
	size_t	l1;
	size_t	l2;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	if (l1 < l2)
		return (ft_strncmp(s1, s2, l2 + 1));
	else
		return (ft_strncmp(s1, s2, l1 + 1));
}
