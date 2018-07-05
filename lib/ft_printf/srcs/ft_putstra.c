/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstra.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:28:02 by syboeuf           #+#    #+#             */
/*   Updated: 2018/04/04 08:47:29 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putstra2(char *str, t_p *p, int a, int i)
{
	if (p->choix == 3)
		mettre_zero(a, p);
	if (p->espace == 2 && p->choix == 0)
		ft_putespace(p);
	if (a == 0)
		ft_putstr("", p);
	else if (p->point == 1)
		while (++i < p->e2 && str[i])
			ft_putchar(str[i], p);
	else
		ft_putstr(str, p);
	if (p->choix == 2)
		justify(p);
}

void	ft_putstra(char *str, t_p *p)
{
	int i;
	int a;

	a = ft_strlen(str);
	i = -1;
	if (str == NULL && p->choix == 0)
		ft_putstr("(null)", p);
	if (p->e && p->point == 1 && p->e2 == 0)
		p->e = p->e;
	else if (p->e2 > a)
		p->e = p->e > a ? p->e - a : 0;
	else if (p->e && p->e2 && a)
		p->e = p->e > p->e2 ? p->e - p->e2 : 0;
	else
		p->e = p->e - a;
	ft_putstra2(str, p, a, i);
}
