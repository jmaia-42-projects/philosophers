/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mind.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:03:54 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/16 15:07:58 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MIND_H
# define MIND_H

# include <stddef.h>

# include "lists.h"

typedef struct s_mind
{
	t_list	*begin;
}	t_mind;

t_mind	*mind_init(void);
void	*mind_malloc(t_mind *mind, size_t size);
void	mind_free(t_mind *mind, void *ptr);
int		mind_add(t_mind *mind, void *ptr);
void	mind_remove(t_mind *mind, void *ptr);
void	mind_blow(t_mind *mind);

#endif
