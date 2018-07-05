/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:32:59 by syboeuf           #+#    #+#             */
/*   Updated: 2018/04/04 12:54:05 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		coor_check(char *str, char *file)
{
	char	*tmp;
	int		i;

	tmp = ft_strdup(str);
	tmp = ft_sfstrjoin(tmp, "\n", 1);
	if (!ft_strstr(file, tmp))
		i = 0;
	else
		i = 1;
	ft_strdel(&tmp);
	return (i);
}

int		print_road(t_list **l, t_room **r, t_infos infos)
{
	t_list	*list;
	t_room	*room;
	int		i;

	i = -1;
	list = *l;
	while (list)
	{
		room = find_room(r, list->content);
		if (room->ants > 0 && room->ants <= infos.n_ants &&
		strcmp(room->room2, infos.start.room2) != 0)
		{
			if (ft_strcmp(list->next->content, infos.start.room2)
			!= 0 && room->ants != infos.n_ants)
				ft_printf("L%d-%s ", room->ants, list->content);
			else
				ft_printf("L%d-%s\n", room->ants, list->content);
			i = 0;
		}
		list = list->next;
	}
	if (i == 0)
		return (0);
	else
		return (-1);
}

void	walking_ants(t_list **l, t_room **r, t_infos infos)
{
	int		flag;
	t_room	*room_a;
	t_list	*road;

	flag = 0;
	room_a = find_room(r, infos.start.room2);
	room_a->ants = 1;
	while (flag != -1)
	{
		road = *l;
		flag = -1;
		while (road && road->next)
		{
			room_a = find_room(r, road->next->content);
			if (room_a->ants != 0)
				((find_room(r, road->content))->ants)++;
			road = road->next;
		}
		flag = print_road(l, r, infos);
	}
}
