/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mind_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:15:46 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/18 18:11:12 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mind.h"

#include <stdlib.h>

void	mind_remove(t_mind *mind, void *ptr)
{
	int		is_found;
	t_list	*cur;
	t_list	*prev;

	prev = 0;
	cur = mind->begin;
	is_found = 0;
	while (cur && !is_found)
	{
		if (cur->content == ptr)
		{
			if (prev)
				prev->next = cur->next;
			else
				mind->begin = cur->next;
			free(cur);
			is_found = 1;
		}
		prev = cur;
		cur = cur->next;
	}
}
