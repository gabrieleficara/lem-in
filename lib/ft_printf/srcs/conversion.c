/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:57:41 by syboeuf           #+#    #+#             */
/*   Updated: 2018/02/14 16:18:54 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	conversion_u(t_p *p, char u)
{
	char *array;
	char c;

	if (u == 'U')
		p->nombre = (unsigned long long int)p->nombre3;
	u = 'a';
	if (p->nombre == 0 && p->point == 1 && p->e2 == 0)
		ft_putstr("", p);
	else
	{
		array = ft_strdup("0123456789");
		c = array[p->nombre % 10];
		if ((p->nombre / 10) != 0)
		{
			p->nombre = p->nombre / 10;
			conversion_u(p, u);
		}
		ft_putchar(c, p);
		ft_strdel(&array);
	}
}

int		conversion_binaire2(int c)
{
	int i;

	i = 0;
	while (c > 0)
	{
		c = c / 2;
		i++;
	}
	return (i);
}

void	conversion_octet(t_p *p, char o)
{
	char *array;
	char c;

	if (o == 'O')
		p->nombre = (unsigned long long int)p->nombre3;
	if (p->e2 == 0 && p->point == 1 && p->nombre == 0)
		ft_putstr("", p);
	else
	{
		o = 'a';
		array = ft_strdup("01234567");
		c = array[p->nombre % 8];
		if ((p->nombre / 8) != 0)
		{
			p->nombre = p->nombre / 8;
			conversion_octet(p, o);
		}
		ft_putchar(c, p);
		ft_strdel(&array);
	}
}

void	conversion_big_x(t_p *p)
{
	char *array;
	char c;

	if (p->e2 == 0 && p->point == 1 && p->nombre == 0)
		ft_putstr("", p);
	else
	{
		array = ft_strdup("0123456789ABCDEF");
		c = array[p->nombre % 16];
		if ((p->nombre / 16) != 0)
		{
			p->nombre = p->nombre / 16;
			conversion_big_x(p);
		}
		ft_putchar(c, p);
		ft_strdel(&array);
	}
}

void	conversion_mini_x(t_p *p)
{
	char *array;
	char c;

	if (p->e2 == 0 && p->point == 1 && p->nombre == 0)
		ft_putstr("", p);
	else
	{
		array = ft_strdup("0123456789abcdef");
		c = array[p->nombre % 16];
		if ((p->nombre / 16) != 0)
		{
			p->nombre = p->nombre / 16;
			conversion_mini_x(p);
		}
		ft_putchar(c, p);
		ft_strdel(&array);
	}
}
