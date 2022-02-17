/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 16:22:25 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/17 14:23:35 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_TIMESTAMP_H
# define GET_TIMESTAMP_H

# include <sys/time.h>

suseconds_t	get_timestamp(struct timeval *start);
void		ft_timersub(struct timeval *a, struct timeval *b,
				struct timeval *res);

#endif
