/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 09:30:43 by syboeuf           #+#    #+#             */
/*   Updated: 2018/02/14 16:11:57 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		binaire(int i)
{
	if (i <= 7)
		return (1);
	else if (i <= 11)
		return (2);
	else if (i > 11 && i <= 16)
		return (3);
	else
		return (4);
}

void	affichage_unicode(char *str, int i, t_p *p)
{
	if (i <= 11)
	{
		ft_putchar(str[0], p);
		ft_putchar(str[1], p);
	}
	else if (i <= 16)
	{
		ft_putchar(str[0], p);
		ft_putchar(str[1], p);
		ft_putchar(str[2], p);
	}
	else
	{
		ft_putchar(str[0], p);
		ft_putchar(str[1], p);
		ft_putchar(str[2], p);
		ft_putchar(str[3], p);
	}
}

void	suite(wint_t wint, char *str, int i, t_p *p)
{
	if (i <= 7)
		ft_putchar(wint, p);
	else if (i <= 11)
	{
		str[0] = (((wint & 0x07c0) >> 6) + 0xc0);
		str[1] = ((wint & 0x003F) + 0x80);
		affichage_unicode(str, i, p);
	}
	else if (i <= 16)
	{
		str[0] = (((wint & 0xF000) >> 12) + 0xE0);
		str[1] = (((wint & 0x0Fc0) >> 6) + 0x80);
		str[2] = ((wint & 0x003F) + 0x80);
		affichage_unicode(str, i, p);
	}
	else
	{
		str[0] = (((wint & 0x1c0000) >> 18) + 0xF0);
		str[1] = (((wint & 0x03F000) >> 12) + 0x80);
		str[2] = (((wint & 0x0Fc0) >> 6) + 0x80);
		str[3] = ((wint & 0x003F) + 0x80);
		affichage_unicode(str, i, p);
	}
}

void	conversion_binaire(wint_t wint, t_p *p)
{
	char	str[4];
	int		i;

	i = conversion_binaire2(wint);
	suite(wint, str, i, p);
}
