/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_state.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 09:39:16 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/20 09:41:46 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_STATE_H
# define SIMULATION_STATE_H

typedef struct s_simulation_state
{
	int				is_simulation_over;
	pthead_mutex_t	is_simulation_over_lock;
}	t_simulation_state;

#endif
