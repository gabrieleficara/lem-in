/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choix_pointeur.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:32:16 by syboeuf           #+#    #+#             */
/*   Updated: 2018/02/14 15:54:52 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	pointeur_2(void const *c, t_p *p, int i, int a)
{
	if ((unsigned int)c <= 0)
		a = 4;
	p->e = p->e > i ? p->e - i - a : 0;
	p->e2 = p->e2 > i ? p->e2 - i : 0;
	if (p->choix == 10)
	{
		p->e = p->e - p->e2;
		ft_putespace(p);
		i = 0;
	}
	else if (p->espace == 2 && p->choix == 0)
		ft_putespace(p);
	if (p->nombrep > 0)
	{
		ft_putstr("0x", p);
		p->e = p->e - 4;
	}
	if (p->choix == 3 && (unsigned int)c != 0)
		mettre_zero(p->nombre, p);
	if (p->point == 1 && p->nombrep > 0)
		mettre_zero((int)p->nombrep, p);
	conversion_p(c, p);
	if (p->choix == 2)
		justify(p);
}

void	pointeur(void const *c, t_p *p)
{
	int i;
	int a;

	a = 2;
	if (p->e2 && p->e && p->choix != 2)
		p->choix = 10;
	if ((unsigned int)c == 0)
	{
		i = 0;
		a = 0;
		p->e++;
	}
	else
		i = width_int('x', (unsigned int)c) + 1;
	if ((unsigned int)c <= 0)
		a = 4;
	pointeur_2(c, p, i, a);
}
