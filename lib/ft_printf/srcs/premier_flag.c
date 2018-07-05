/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   premier_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:23:24 by syboeuf           #+#    #+#             */
/*   Updated: 2018/02/14 16:07:09 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	mettre_zero(int nombre, t_p *p)
{
	int a;

	a = nombre;
	if (p->choix == 3)
		p->e2 = p->e;
	if (p->espace == 1 && p->point == 1)
		ft_putchar(' ', p);
	else if (p->choix == 3 && p->espace == 1 && !p->e)
	{
		p->e2--;
		ft_putchar(' ', p);
	}
	p->e2 = p->e2 > 0 ? p->e2 : 0;
	a = 0;
	if (p->e2)
		while (a++ < p->e2)
			ft_putnbr(0, p);
	p->e = p->e - p->e2;
}

void	plus(int nombre, char *nb, t_p *p)
{
	int i;
	int a;

	a = nombre;
	a = p->e;
	i = '0';
	while (i++ <= '9')
		if (ft_strchr("0123456789", i))
			nb[i - 1] = '+';
}

void	ft_putespace(t_p *p)
{
	p->e = p->e > 0 ? p->e : 0;
	while (p->e-- > 0)
		ft_putchar(' ', p);
}

void	justify(t_p *p)
{
	p->e = p->e > 0 ? p->e : 0;
	while (p->e-- > 0)
		ft_putchar(' ', p);
}

void	diese(char c, t_p *p)
{
	if (c == 'o' || c == 'O')
		ft_putchar('0', p);
	else if (c == 'x')
		ft_putstr("0x", p);
	else if (c == 'X')
		ft_putstr("0X", p);
}
