/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:30:44 by syboeuf           #+#    #+#             */
/*   Updated: 2017/11/15 14:45:11 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*array;
	int		i;
	int		k;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	k = 0;
	if (!(array = (char*)malloc(sizeof(char)
					* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (s1[i])
	{
		array[i] = s1[i];
		i++;
	}
	while (s2[k])
	{
		array[i + k] = s2[k];
		k++;
	}
	array[i + k] = '\0';
	return (array);
}
