/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 15:52:54 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/16 14:58:47 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = malloc(sizeof(*elem));
	if (elem == 0)
		return (0);
	elem->content = content;
	elem->next = 0;
	return (elem);
}
