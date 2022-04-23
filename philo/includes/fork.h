/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:29:29 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/23 11:31:39 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORK_H
# define FORK_H

typedef struct s_fork
{
	int				fork_owner;
	pthread_mutex_t	fork_owner_lock;
}	t_fork;

#endif
