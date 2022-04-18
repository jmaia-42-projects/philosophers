/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:39:16 by jmaia             #+#    #+#             */
/*   Updated: 2022/04/16 10:38:39 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_ARGS_H
# define PARSE_ARGS_H

# include <stdlib.h>

# include "it_is_not_libft_hoho.h"

# include "philos_infos.h"

int	parse_args_and_print_error(t_philos_infos **pi, int ac, char **av);
int	parse_args(t_philos_infos **pi, int ac, char **av);

#endif
