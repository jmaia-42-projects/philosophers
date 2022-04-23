/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeval_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:35:19 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/23 11:59:02 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timeval_ops.h"

int	is_greater_than(struct timeval a, struct timeval b)
{
	if (a.tv_sec > b.tv_sec)
		return (1);
	if (a.tv_sec == b.tv_sec && a.tv_usec > b.tv_usec)
		return (1);
	return (0);
}

struct timeval	time_diff(struct timeval a, struct timeval b)
{
	struct timeval	diff;

	diff.tv_sec = a.tv_sec - b.tv_sec;
	diff.tv_usec = a.tv_usec - b.tv_usec;
	while (diff.tv_usec < 0)
	{
		diff.tv_usec += 1000000;
		diff.tv_sec--;
	}
	return (diff);
}

struct timeval	sum(struct timeval a, unsigned long us)
{
	a.tv_usec += us;
	a.tv_sec += a.tv_usec / 1000000;
	a.tv_usec %= 1000000;
	return (a);
}
