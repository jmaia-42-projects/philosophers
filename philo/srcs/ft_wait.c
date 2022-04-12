/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:13:41 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/12 14:59:28 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>

#include "ft_wait.h"

static int				is_greater_than(struct timeval a, struct timeval b);
static struct timeval	time_diff(struct timeval a, struct timeval b);

void	ft_wait_ms_until(unsigned long time_point_ms,
	struct timeval *p_ref_time)
{
	struct timeval	time_point;

	time_point.tv_sec = time_point_ms / 1000;
	time_point.tv_usec = time_point_ms % 1000 * 1000;
	ft_wait_until(time_point, p_ref_time);
}

void	ft_wait_until(struct timeval time_point, struct timeval *p_ref_time)
{
	static struct timeval	ref_time;
	struct timeval			now;

	if (p_ref_time)
		ref_time = *p_ref_time;
	gettimeofday(&now, 0);
	while (!is_greater_than(time_diff(now, time_point), ref_time))
	{
		usleep(1);
		gettimeofday(&now, 0);
	}
}

static int	is_greater_than(struct timeval a, struct timeval b)
{
	if (a.tv_sec > b.tv_sec)
		return (1);
	if (a.tv_sec == b.tv_sec && a.tv_usec > b.tv_usec)
		return (1);
	return (0);
}

static struct timeval	time_diff(struct timeval a, struct timeval b)
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
