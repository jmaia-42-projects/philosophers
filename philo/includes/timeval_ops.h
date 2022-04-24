/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timeval_ops.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 11:36:21 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/23 11:59:12 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIMEVAL_OPS_H
# define TIMEVAL_OPS_H

# include <sys/time.h>

int				is_greater_than(struct timeval a, struct timeval b);
struct timeval	time_diff(struct timeval a, struct timeval b);
struct timeval	sum(struct timeval a, unsigned long us);

#endif
