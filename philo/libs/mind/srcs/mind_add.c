/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mind_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:12:47 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/16 15:14:56 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mind.h"

int	mind_add(t_mind *mind, void *ptr)
{
	t_list	*elem;

	elem = ft_lstnew(ptr);
	if (!elem)
		return (1);
	ft_lstadd_front(&mind->begin, elem);
	return (0);
}
