/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   appel_pourcentage.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 14:56:12 by syboeuf           #+#    #+#             */
/*   Updated: 2018/02/14 15:54:21 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	appel_pourcentage(t_p *p)
{
	p->e--;
	if (p->choix == 3)
		mettre_zero(p->e, p);
	if (p->espace == 2 && p->choix == 0)
		ft_putespace(p);
	ft_putchar('%', p);
	if (p->choix == 2)
		justify(p);
}
