/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wait.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 12:40:25 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/12 14:59:51 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_WAIT_H
# define FT_WAIT_H

void	ft_wait_ms_until(unsigned long wait_time_ms,
			struct timeval *p_ref_time);
void	ft_wait_until(struct timeval wait_time, struct timeval *p_ref_time);

#endif
