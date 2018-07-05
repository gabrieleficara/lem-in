/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:33:42 by syboeuf           #+#    #+#             */
/*   Updated: 2018/02/14 16:10:49 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	return_int(va_list *va, t_p *p)
{
	if (p->hh == 1)
		p->nombre2 = (char)va_arg(*va, long long int);
	else if (p->h == 1)
		p->nombre2 = (short int)va_arg(*va, long long int);
	else if (p->l == 1)
		p->nombre2 = (long int)va_arg(*va, long long int);
	else if (p->ll == 1)
		p->nombre2 = (long long int)va_arg(*va, long long int);
	else if (p->j == 1)
		p->nombre2 = (intmax_t)va_arg(*va, long long int);
	else if (p->z == 1)
		p->nombre2 = (size_t)va_arg(*va, long long int);
	else
		p->nombre2 = (int)va_arg(*va, long long int);
}

void	return_unsigned_int(va_list *va, t_p *p)
{
	if (p->hh == 1)
		p->nombre = (unsigned char)va_arg(*va, unsigned long long int);
	else if (p->h == 1)
		p->nombre = (unsigned short int)va_arg(*va, unsigned long long int);
	else if (p->l == 1)
		p->nombre = (unsigned long int)va_arg(*va, unsigned long long int);
	else if (p->ll == 1)
		p->nombre = (unsigned long long int)va_arg(*va, unsigned long long int);
	else if (p->j == 1)
		p->nombre = (intmax_t)va_arg(*va, unsigned long long int);
	else if (p->z == 1)
		p->nombre = (size_t)va_arg(*va, unsigned long long int);
	else
		p->nombre = (unsigned int)va_arg(*va, unsigned long long int);
}

void	return_long_int(va_list *va, t_p *p)
{
	p->nombre3 = (unsigned long int)va_arg(*va, long int);
}
