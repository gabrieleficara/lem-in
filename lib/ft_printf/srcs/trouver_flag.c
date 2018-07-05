/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trouver_flag.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:35:06 by syboeuf           #+#    #+#             */
/*   Updated: 2018/02/14 16:09:33 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	degeulasse(t_p *p, int i)
{
	p->z = 0;
	p->j = 0;
	p->ll = 0;
	p->l = 0;
	p->h = 0;
	p->hh = 0;
	if (i == 1)
		p->z = 1;
	else if (i == 2)
		p->j = 1;
	else if (i == 3)
		p->l = 1;
	else if (i == 4)
		p->ll = 1;
	else if (i == 5)
		p->h = 1;
	else if (i == 6)
		p->hh = 1;
}

void	flag_finale(t_p *p)
{
	if (p->z == 1)
		degeulasse(p, 1);
	else if (p->j == 1)
		degeulasse(p, 2);
	else if (p->l == 1)
		degeulasse(p, 3);
	else if (p->ll == 1)
		degeulasse(p, 4);
	else if (p->h == 1)
		degeulasse(p, 5);
	else if (p->hh == 1)
		degeulasse(p, 6);
}

void	find_other_flag(char const *str, int *j, t_p *p)
{
	while (ft_strchr("hljz", str[*j]))
	{
		if (str[*j] == 'h')
			p->h++;
		else if (str[*j] == 'l')
			p->l++;
		else if (str[*j] == 'j')
			p->j++;
		else if (str[*j] == 'z')
			p->z++;
		(*j)++;
	}
	if (p->h == 2)
	{
		p->hh = 1;
		p->h = 0;
	}
	if (p->l == 2)
	{
		p->ll = 1;
		p->l = 0;
	}
	flag_finale(p);
}

void	abuser(const char *str, int *j, t_p *p)
{
	if (str[*j] == '+')
	{
		p->plus = 1;
		p->plus2 = 1;
		(*j)++;
	}
}

void	find_flag(const char *str, int *j, t_p *p)
{
	while (ft_strchr("-+#0 ", str[*j]) && str[*j])
		ecrire(str[(*j)++], p);
	if (str[*j] >= '0' && str[*j] <= '9')
	{
		while (str[*j] >= '0' && str[*j] <= '9')
			p->e = p->e * 10 + (str[(*j)++] - 48);
		if (p->espace == 1)
		{
			p->e--;
			ft_putchar(' ', p);
		}
		p->espace = 2;
	}
	if (str[*j] == '.')
	{
		p->point = 1;
		(*j)++;
		while (str[*j] >= '0' && str[*j] <= '9')
			p->e2 = p->e2 * 10 + (str[(*j)++] - 48);
	}
}
