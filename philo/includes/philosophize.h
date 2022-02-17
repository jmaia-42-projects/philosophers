/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophize.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:08:19 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/17 15:19:09 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHIZE_H
# define PHILOSOPHIZE_H

# include <pthread.h>
# include <stdlib.h>

# include "philos_infos.h"
# include "live.h"

int	philosophize(t_philos_infos pi);

#endif
