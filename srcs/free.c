/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:32:20 by syboeuf           #+#    #+#             */
/*   Updated: 2018/04/04 12:52:32 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	freelinks(t_links **tmp)
{
	t_links *ok;

	while (*tmp)
	{
		ok = *tmp;
		ft_strdel(&ok->l1);
		ft_strdel(&ok->l2);
		*tmp = ok->next;
		free(ok);
	}
}

void	freed(t_room **tmp)
{
	t_room	*room;
	t_links	*ok;

	while (*tmp)
	{
		room = *tmp;
		ft_strdel(&room->room2);
		ok = room->number;
		freelinks(&ok);
		*tmp = room->next;
		free(room);
	}
}

void	freedoom(char **as)
{
	int i;

	i = -1;
	while (as[++i])
		ft_strdel(as + i);
	free(as);
}

void	delfun(void *str, size_t num)
{
	ft_strdel((char**)&str);
	num = 0;
}
