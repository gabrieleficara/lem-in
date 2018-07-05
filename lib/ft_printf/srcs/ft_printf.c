/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:50:57 by syboeuf           #+#    #+#             */
/*   Updated: 2018/02/15 11:08:52 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	initialisation(t_p *p)
{
	p->hh = 0;
	p->h = 0;
	p->l = 0;
	p->ll = 0;
	p->j = 0;
	p->z = 0;
	p->espace = 0;
	p->l1 = 0;
	p->choix = 0;
	p->e = 0;
	p->point = 0;
	p->e2 = 0;
	p->nb = 0;
	p->plus = 0;
	p->diese = 0;
}

void	premiere_partie(const char *str, int *j, t_p *p, va_list *va)
{
	(*j)++;
	find_flag(str, j, p);
	find_other_flag(str, j, p);
	find_flag(str, j, p);
	specifier(str, j, p, va);
}

void	second_partie(char mot, t_p *p)
{
	if (!ft_strchr("sSpdDioOuUxXcC%", mot))
	{
		if (p->choix == 3)
		{
			p->e--;
			mettre_zero(p->e, p);
			ft_putchar(mot, p);
		}
		else if (p->choix == 2)
		{
			ft_putchar(mot, p);
			p->e--;
			ft_putespace(p);
		}
		else if (p->espace == 2)
		{
			p->e--;
			ft_putespace(p);
			ft_putchar(mot, p);
		}
		else
			ft_putchar(mot, p);
	}
}

int		ft_printf(const char *str, ...)
{
	va_list		va;
	t_p			p;
	int			j;

	va_start(va, str);
	j = -1;
	p.total = 0;
	while (str[++j])
	{
		initialisation(&p);
		if (str[j] == '%')
		{
			if (str[j + 1] == '\0')
				return (p.total);
			premiere_partie(str, &j, &p, &va);
			if (str[j - 1] == '\0' || str[j] == '\0')
				return (p.total);
			second_partie(str[j], &p);
		}
		else
			ft_putchar(str[j], &p);
	}
	va_end(va);
	return (p.total);
}
