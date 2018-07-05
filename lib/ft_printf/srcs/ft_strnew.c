/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:46:33 by syboeuf           #+#    #+#             */
/*   Updated: 2017/11/15 14:55:17 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strnew(size_t size)
{
	char	*array;
	size_t	i;

	i = 0;
	array = (char *)malloc(sizeof(char) * (size + 1));
	if (array == NULL)
		return (NULL);
	while (i < size)
	{
		array[i] = '\0';
		i++;
	}
	array[i] = 0;
	return (array);
}
