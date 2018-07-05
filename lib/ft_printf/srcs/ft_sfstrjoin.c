/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sfstrjoin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 09:48:28 by syboeuf           #+#    #+#             */
/*   Updated: 2018/04/03 09:48:58 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_sfstrjoin(char const *s1, char const *s2, int c)
{
	char *ret;

	ret = ft_strjoin(s1, s2);
	if (c == 1 || c == 3)
		ft_strdel((char **)&s1);
	if (c == 2 || c == 3)
		ft_strdel((char **)&s2);
	return (ret);
}
