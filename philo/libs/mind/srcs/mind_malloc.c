/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mind_malloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:02:08 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/16 15:10:20 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mind.h"

#include <stdlib.h>

void	*mind_malloc(t_mind *mind, size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
		mind_blow(mind);
	else
		mind_add(mind, ptr);
	return (ptr);
}
