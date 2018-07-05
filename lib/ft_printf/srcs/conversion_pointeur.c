/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_pointeur.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:30:38 by syboeuf           #+#    #+#             */
/*   Updated: 2018/02/16 10:23:14 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	conversion_p2(unsigned long adr, t_p *p)
{
	char const	*base;
	char		c;

	base = "0123456789abcdef";
	c = base[(adr % 16)];
	if ((adr / 16) != 0)
		conversion_p2(adr / 16, p);
	ft_putchar(c, p);
}

void	conversion_p(void const *c, t_p *p)
{
	unsigned long adr;

	adr = (unsigned long)c;
	if (p->e2 == 0 && p->point == 1 && adr == 0)
		ft_putstr("0x", p);
	else if (adr == 0)
	{
		ft_putstr("0x0", p);
		p->e2--;
		if (p->point == 1 || p->choix == 3)
			mettre_zero(adr, p);
	}
	else
		conversion_p2(adr, p);
}
