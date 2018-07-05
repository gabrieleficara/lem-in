/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/10 15:30:03 by syboeuf           #+#    #+#             */
/*   Updated: 2018/02/14 16:20:09 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	specifier3(char const *str, int *j, t_p *p, va_list *va)
{
	if (str[*j] == 'U')
	{
		return_long_int(va, p);
		apel(str[*j], p);
	}
	else if (str[*j] == '%')
		appel_pourcentage(p);
	else if (str[*j] == 'p')
	{
		p->nombrep = va_arg(*va, void*);
		pointeur((const void*)p->nombrep, p);
	}
	else if (str[*j] == 'O')
	{
		return_long_int(va, p);
		apel(str[*j], p);
	}
	else if (str[*j] == 'D')
	{
		return_long_int(va, p);
		ft_putnbra(p->nombre3, p, str[*j]);
	}
}

void	specifier2(char const *str, int *j, t_p *p, va_list *va)
{
	if (str[*j] == 'o' || str[*j] == 'x' || str[*j] == 'X' || str[*j] == 'u')
	{
		return_unsigned_int(va, p);
		apel(str[*j], p);
	}
	else if (str[*j] == 'd' || str[*j] == 'i')
	{
		return_int(va, p);
		ft_putnbra(p->nombre2, p, str[*j]);
	}
	else if (str[*j] == 's')
	{
		if (p->l == 1)
			conversion_grand_s(va, p);
		else
		{
			p->array = va_arg(*va, char*);
			ft_putstra(p->array, p);
		}
	}
}

void	specifier(char const *str, int *j, t_p *p, va_list *va)
{
	if (str[*j] == 'c')
	{
		if (p->l == 1)
		{
			p->arraywchar = va_arg(*va, wint_t);
			conversion_binaire(p->arraywchar, p);
		}
		else
		{
			p->caractere = va_arg(*va, int);
			appel_caractere(p);
		}
	}
	else if (str[*j] == 'C' || str[*j] == 'S')
	{
		if (str[*j] == 'S')
			conversion_grand_s(va, p);
		else
		{
			p->arraywchar = va_arg(*va, wint_t);
			conversion_binaire(p->arraywchar, p);
		}
	}
	specifier2(str, j, p, va);
	specifier3(str, j, p, va);
}
