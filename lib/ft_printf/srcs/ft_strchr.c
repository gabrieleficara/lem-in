/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:11:20 by syboeuf           #+#    #+#             */
/*   Updated: 2017/11/15 14:51:20 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	letter;
	size_t			i;

	i = 0;
	letter = c;
	while (i <= ft_strlen(s))
	{
		if (s[i] == letter)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}
