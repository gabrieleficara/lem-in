/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_decimal.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 15:39:51 by syboeuf           #+#    #+#             */
/*   Updated: 2018/02/14 17:10:26 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ecrire(char c, t_p *p)
{
	if (c == '+')
		p->plus = 1;
	if (c == ' ')
		p->espace = 1;
	if (c == '-')
		p->choix = 2;
	if (c == '#')
		p->diese = 1;
	if (c == '0')
		if (p->choix != 2)
			p->choix = 3;
}

void	decimal(unsigned int nb, t_p *p)
{
	char *array;
	char c;

	array = ft_strdup("0123456789");
	c = array[nb % 10];
	if ((nb / 10) != 0)
		decimal((nb / 10), p);
	ft_putchar(c, p);
}
