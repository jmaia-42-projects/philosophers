/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:13:41 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/12 12:56:02 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/time.h>
#include <unistd.h>

#include "ft_wait.h"

static int				is_greater_than(struct timeval a, struct timeval b);
static struct timeval	time_diff(struct timeval a, struct timeval b);
static struct timeval	time_sum(struct timeval a, struct timeval b);

void	ft_wait_ms(unsigned long wait_time_ms, struct timeval *ref_time)
{
	struct timeval	wait_time;

	wait_time.tv_sec = wait_time_ms / 1000;
	wait_time.tv_usec = wait_time_ms % 1000 * 1000;
	ft_wait(wait_time, ref_time);
}

void	ft_wait(struct timeval wait_time, struct timeval *ref_time)
{
	struct timeval			now;

	gettimeofday(&now, 0);
	while (is_greater_than(time_diff(now, *ref_time), wait_time))
	{
		usleep(1);
		gettimeofday(&now, 0);
	}
	*ref_time = time_sum(*ref_time, wait_time);
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

static struct timeval	time_sum(struct timeval a, struct timeval b)
{
	struct timeval	sum;

	sum.tv_usec = a.tv_usec + b.tv_usec;
	sum.tv_sec = a.tv_sec + b.tv_sec + sum.tv_usec / 1000000;
	sum.tv_usec %= 1000000;
	return (sum);
}
