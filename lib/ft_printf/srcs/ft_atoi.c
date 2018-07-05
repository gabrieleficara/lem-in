/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 17:16:32 by syboeuf           #+#    #+#             */
/*   Updated: 2017/11/17 08:46:02 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		ft_convertion(int resultat, int i, int negative)
{
	if (i > 18 && negative == 1)
		return (0);
	else if (i > 18)
		return (-1);
	else if (negative == 1)
		resultat = -resultat;
	return (resultat);
}

int				ft_atoi(const char *nptr)
{
	int resultat;
	int i;
	int negative;

	resultat = 0;
	i = 0;
	negative = 0;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (!(nptr[i] >= 48 && nptr[i] <= 57))
	{
		if (nptr[i] == '-')
			negative = 1;
		else if (nptr[i] != '+')
			return (0);
		i++;
	}
	while (nptr[i] >= 48 && nptr[i] <= 57)
		resultat = resultat * 10 + (nptr[i++] - 48);
	return (ft_convertion(resultat, i, negative));
}
