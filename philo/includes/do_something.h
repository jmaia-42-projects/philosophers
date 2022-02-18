/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_something.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 15:36:10 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/18 12:19:09 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DO_SOMETHING_H
# define DO_SOMETHING_H

# include <stdio.h>
# include <sys/time.h>

# include "actions.h"
# include "get_timestamp.h"
# include "philos_infos.h"
# include "world.h"

void	do_something(int philo_id, t_action action, t_world *world);

#endif
