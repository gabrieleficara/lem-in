/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:32:45 by syboeuf           #+#    #+#             */
/*   Updated: 2018/04/04 12:32:47 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

char	*name_room(char *s)
{
	int		i;
	char	*tmp;

	i = 0;
	while (s[i] && s[i] != ' ')
		i++;
	if (!(tmp = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != ' ')
	{
		tmp[i] = s[i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

void	addroom(t_room **room, int nb, char *tmp)
{
	t_room *new;

	new = ft_memalloc(sizeof(t_room));
	new->room = nb;
	new->room2 = ft_strdup(tmp);
	new->ants = 0;
	new->visited = 0;
	new->next = *room;
	*room = new;
}

void	addlink(t_room *room, char *l3, char *l4)
{
	t_links *links;

	links = ft_memalloc(sizeof(t_links));
	links->l1 = l3;
	links->l2 = l4;
	links->next = room->number;
	room->number = links;
}
