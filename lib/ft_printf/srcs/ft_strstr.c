/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 13:10:48 by syboeuf           #+#    #+#             */
/*   Updated: 2017/11/16 14:15:01 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_strstr(const char *meule_de_foin, const char *aiguille)
{
	int i;
	int j;

	i = 0;
	if (aiguille[0] == '\0')
		return ((char *)meule_de_foin);
	while (meule_de_foin[i] != '\0')
	{
		j = 0;
		while (meule_de_foin[i + j] == aiguille[j])
		{
			if (aiguille[j + 1] == '\0')
				return ((char *)meule_de_foin + i);
			j++;
		}
		i++;
	}
	return (0);
}
