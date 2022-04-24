/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   it_is_not_libft_hoho.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaia <jmaia@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 15:10:00 by jmaia             #+#    #+#             */
/*   Updated: 2022/02/08 17:21:36 by jmaia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IT_IS_NOT_LIBFT_HOHO_H
# define IT_IS_NOT_LIBFT_HOHO_H

# include <stddef.h>

int				ft_atoi(const char *nptr);
int				ft_isdigit(int c);
int				ft_isint(char *nbr);
int				ft_isnbr(const char *nbr);
int				ft_isspace(int c);
unsigned char	*ft_itoa(long long nbr);
unsigned char	*ft_itoa_base(long long nbr, char *base);
int				ft_strcmp(char *s1, char *s2);
size_t			ft_strlen(const char *s);
int				ft_strncmp(const char *s1, const char *s2, size_t n);

#endif
