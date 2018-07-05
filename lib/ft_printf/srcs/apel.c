/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apel.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:29:10 by syboeuf           #+#    #+#             */
/*   Updated: 2018/02/14 15:53:27 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	apel3(char c, t_p *p, int i)
{
	if (p->diese == 1 && (p->nombre != 0))
		diese(c, p);
	else if (p->diese == 1 && p->e2 == 0 && p->point == 1
			&& (c == 'o' || c == 'O'))
		diese(c, p);
	if (p->choix == 3)
		mettre_zero(p->nombre, p);
	if (p->point == 1 && p->nombre > 0)
		mettre_zero(p->nombre, p);
	if (c == 'o' || c == 'O')
		conversion_octet(p, c);
	else if (c == 'x')
		conversion_mini_x(p);
	else if (c == 'X')
		conversion_big_x(p);
	else if (c == 'u' || c == 'U')
		conversion_u(p, c);
	if (p->choix == 2 && i)
		justify(p);
}

void	apel2(char c, t_p *p, int i)
{
	if ((c == 'o' || c == 'O') && p->diese == 1 && p->nombre != 0)
	{
		p->e--;
		p->e2--;
	}
	else if ((c == 'x' || c == 'X') && p->diese == 1 && p->nombre != 0)
		p->e = p->e - 2;
	if (p->choix == 10)
	{
		p->e = p->e - p->e2;
		ft_putespace(p);
		i = 0;
	}
	else if (p->espace == 2 && p->choix == 0)
		ft_putespace(p);
}

void	apel(char c, t_p *p)
{
	int i;

	if (c == 'U' || c == 'O')
		p->nombre = (unsigned long long int)p->nombre3;
	if (p->e && p->e2 && p->choix != 2)
		p->choix = 10;
	i = width_int(c, (unsigned int)p->nombre) + 1;
	if (p->nombre == 0)
		i = 0;
	p->e = p->e > i ? p->e - i : 0;
	p->e2 = p->e2 > i ? p->e2 - i : 0;
	apel2(c, p, i);
	apel3(c, p, i);
}
