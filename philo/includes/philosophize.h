/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophize.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:08:19 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/18 11:19:59 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHIZE_H
# define PHILOSOPHIZE_H

# include <pthread.h>
# include <stdlib.h>

# include "philos_infos.h"
# include "live.h"

int	philosophize(t_philos_infos *pi);

#endif
