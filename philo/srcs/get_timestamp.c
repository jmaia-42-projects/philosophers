/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:38:23 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/17 14:24:48 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_timestamp.h"

suseconds_t	get_timestamp(struct timeval *start)
{
	suseconds_t		timestamp;
	struct timeval	raw_timestamp;
	struct timeval	now;
	int				err;

	err = gettimeofday(&now, 0);
	if (err)
		return (-1);
	ft_timersub(&now, start, &raw_timestamp);
	timestamp = raw_timestamp.tv_sec * 10000000 + raw_timestamp.tv_usec;
	return (timestamp);
}

void	ft_timersub(struct timeval *a, struct timeval *b, struct timeval *res)
{
	res->tv_sec = a->tv_sec - b->tv_sec;
	if (a->tv_usec > b->tv_usec)
		res->tv_usec = a->tv_usec - b->tv_usec;
	else
	{
		res->tv_usec = 1000000 + a->tv_usec - b->tv_usec;
		res->tv_sec--;
	}
}
