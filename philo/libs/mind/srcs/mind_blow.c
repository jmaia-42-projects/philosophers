/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mind_blow.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 15:22:28 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/18 18:16:49 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mind.h"

#include <stdlib.h>

void	mind_blow(t_mind *mind)
{
	while (mind->begin)
		mind_free(mind, mind->begin->content);
	free(mind);
}
