/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:33:22 by jmaia             #+#    #+#             */
/*   Updated: 2022/11/28 20:17:36 by jmaia            ###   ###               */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "actions/do_actions.h"
#include "did_philo_starve_to_death.h"
#include "ft_wait.h"
#include "utils.h"
#include "timeval_ops.h"

static void	set_nbr_and_move(char **str, unsigned long nbr);
static void	set_nbr(char **str, unsigned long nbr);

int	do_action(t_philo *philo, unsigned long duration, char *action)
{
	int				err;
	struct timeval	now;
	struct timeval	raw_timestamp;
	unsigned long	timestamp;

	err = 0;
	kill_philo_if_he_starve_to_death(philo);
	sem_wait(philo->state->write_lock);
	gettimeofday(&now, 0);
	raw_timestamp = time_diff(now, philo->state->start);
	timestamp = raw_timestamp.tv_usec / 1000 + raw_timestamp.tv_sec * 1000;
	err = print_action(timestamp, philo->id, action);
	sem_post(philo->state->write_lock);
	philo->timestamp += duration;
	ft_wait_ms_until(philo, philo->timestamp, 0);
	return (err);
}

int	print_action(unsigned long timestamp, unsigned int philo_i,
				char *action)
{
	char	*cur_msg;
	char	*msg;
	int		len_timestamp;
	int		len_philo_i;

	len_timestamp = nbrlen(timestamp);
	len_philo_i = nbrlen(philo_i);
	msg = malloc(sizeof(*msg) * (len_timestamp + len_philo_i + ft_strlen(action)
				+ 2 + 1 + 1));
	if (!msg)
		return (1);
	cur_msg = msg;
	set_nbr_and_move(&cur_msg, timestamp);
	cur_msg++[0] = ' ';
	set_nbr_and_move(&cur_msg, philo_i);
	cur_msg++[0] = ' ';
	ft_strcpy(cur_msg, action);
	cur_msg[ft_strlen(action)] = '\n';
	cur_msg[ft_strlen(action) + 1] = 0;
	write(1, msg, ft_strlen(msg));
	free(msg);
	return (0);
}

static void	set_nbr_and_move(char **str, unsigned long nbr)
{
	set_nbr(str, nbr);
	*str += nbrlen(nbr);
}

static void	set_nbr(char **str, unsigned long nbr)
{
	int	len_nbr;

	len_nbr = nbrlen(nbr);
	if (nbr >= 10)
		set_nbr(str, nbr / 10);
	(*str)[len_nbr - 1] = nbr % 10 + '0';
}
