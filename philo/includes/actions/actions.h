/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:06:12 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/12 18:21:59 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ACTIONS_H
# define ACTIONS_H

# define TAKE_FORK_MSG	"has taken a fork"
# define EAT_MSG		"is eating"
# define SLEEP_MSG		"is sleeping"
# define THINK_MSG		"is thinking"
# define DIE_MSG		"died"

typedef enum e_actions
{
	TAKE_FORK,
	EAT,
	SLEEP,
	THINK,
	DIE
}	t_actions;

#endif
