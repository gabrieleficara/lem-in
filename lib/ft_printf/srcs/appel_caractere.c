/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appel_caractere.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:55:35 by syboeuf           #+#    #+#             */
/*   Updated: 2018/02/14 15:53:55 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	appel_caractere(t_p *p)
{
	p->e--;
	if (p->choix == 3)
		mettre_zero(p->caractere, p);
	if (p->espace == 2 && p->choix == 0)
		ft_putespace(p);
	ft_putchar(p->caractere, p);
	if (p->choix == 2)
		justify(p);
}
