/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_S.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 14:53:02 by syboeuf           #+#    #+#             */
/*   Updated: 2018/02/14 15:58:36 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	affichage(int a, int i, t_p *p, wchar_t *s)
{
	while (s[++i])
	{
		if (p->e2 - (p->total - a) < 0)
			break ;
		a = p->total;
		conversion_binaire(s[i], p);
		p->e2 = p->e2 - (p->total - a);
	}
}

void	partie_3(int a, int i, t_p *p, wchar_t *s)
{
	if (p->espace == 2 && p->choix != 2 && p->choix != 3)
	{
		while (s[++i] && a < p->e)
			a = a + binaire(conversion_binaire2(s[i]));
		p->e = p->e > a ? p->e - a : 0;
		ft_putespace(p);
		i = -1;
		if (p->point != 1)
			while (s[++i])
				conversion_binaire(s[i], p);
	}
	else if (p->point == 1)
	{
		i = -1;
		a = p->total;
		affichage(a, i, p, s);
	}
	else if (p->espace != 2 && p->point == 0)
		while (s[++i])
			conversion_binaire(s[i], p);
}

void	partie_2(int a, int i, t_p *p, wchar_t *s)
{
	if (p->choix == 2)
	{
		while (s[++i] && a < p->e)
			a = a + binaire(conversion_binaire2(s[i]));
		p->e = p->e > a ? p->e - a : 0;
		i = -1;
		if (p->point != 1)
			while (s[++i])
				conversion_binaire(s[i], p);
		justify(p);
	}
	else if (p->choix == 3)
	{
		while (s[++i] && a < p->e)
			a = a + binaire(conversion_binaire2(s[i]));
		p->e = p->e > a ? p->e - a : 0;
		mettre_zero(a, p);
		i = -1;
		if (p->point != 1)
			while (s[++i])
				conversion_binaire(s[i], p);
	}
	partie_3(a, i, p, s);
}

void	partie_1(int a, int i, t_p *p, wchar_t *s)
{
	if (p->choix == 3 && p->point == 1 && p->e2 == 0)
		mettre_zero(p->e, p);
	else if (p->espace == 2 && p->point == 1)
	{
		while (s[++i])
		{
			a = a + binaire(conversion_binaire2(s[i]));
			if (a + binaire(conversion_binaire2(s[i + 1])) > p->e2)
				break ;
		}
		if (p->e2 != 0)
			p->e = p->e > a ? p->e - a : 0;
		ft_putespace(p);
		i = -1;
		a = p->total;
		if (p->e2 > 0)
			affichage(a, i, p, s);
	}
}

void	conversion_grand_s(va_list *va, t_p *p)
{
	int		i;
	int		a;
	wchar_t	*s;

	a = 0;
	s = va_arg(*va, wchar_t*);
	i = -1;
	if (s == NULL)
		ft_putstr("(null)", p);
	else if (s[0] == '\0')
		ft_putstr("", p);
	else
	{
		if ((p->choix || p->espace) && p->point)
			partie_1(a, i, p, s);
		else
			partie_2(a, i, p, s);
	}
}
