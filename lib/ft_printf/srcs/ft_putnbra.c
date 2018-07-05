/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:26:39 by syboeuf           #+#    #+#             */
/*   Updated: 2018/02/14 17:19:35 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbra3(long long int nombre, t_p *p, int *i, int *b)
{
	if (p->plus == 1 || *b == 1)
	{
		if (p->plus == 1 && *b == 0)
		{
			ft_putchar('+', p);
			p->e--;
		}
		else if (*b == 1)
		{
			ft_putchar('-', p);
			p->e--;
		}
	}
	if (p->choix == 3)
		mettre_zero(nombre, p);
	if (p->point == 1)
		mettre_zero(nombre, p);
	ft_putnbr(nombre, p);
	if (p->choix == 2 && *i)
		justify(p);
}

void	ft_putnbra2(t_p *p, int *i, int *b)
{
	if (p->e && p->e2 && p->choix != 2)
		p->choix = 10;
	p->e = p->e > *i ? p->e - *i : 0;
	p->e2 = p->e2 > *i ? p->e2 - *i : 0;
	if (p->choix == 10)
	{
		if (p->plus == 1)
			p->e--;
		if (*b == 0)
			p->e = p->e - p->e2;
		else
			p->e = --p->e - p->e2;
		ft_putespace(p);
		*i = 0;
	}
	else if (p->espace == 2 && p->choix == 0)
	{
		if (p->plus == 1 || p->plus2 == 1 || *b == 1)
			p->e--;
		ft_putespace(p);
	}
}

void	ft_putnbra(long long int nombre, t_p *p, char c)
{
	int i;
	int b;

	b = 0;
	i = 0;
	if (p->espace == 2 && p->point == 1 && p->e2 == 0 && nombre == 0)
		ft_putespace(p);
	else if (p->point == 1 && p->e2 == 0 && nombre == 0)
		return ;
	else if ((unsigned long long int)nombre == -9223372036854775808U)
		ft_putstr("-9223372036854775808", p);
	else
	{
		if (nombre < 0)
		{
			b = 1;
			nombre = -nombre;
		}
		i = width_int(c, nombre) + 1;
		if (p->espace == 1 && p->choix == 0 && p->plus == 0 && b == 0)
			ft_putchar(' ', p);
		ft_putnbra2(p, &i, &b);
		ft_putnbra3(nombre, p, &i, &b);
	}
}
