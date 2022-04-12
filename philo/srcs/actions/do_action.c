/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_action.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 16:33:22 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/12 18:29:32 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

#include "actions/do_actions.h"
#include "utils.h"

static void	set_nbr_and_move(char **str, unsigned long nbr);
static void	set_nbr(char **str, unsigned long nbr);

int	do_action(unsigned long timestamp, unsigned int philo_i, char *action)
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
