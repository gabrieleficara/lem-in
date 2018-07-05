/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   astar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:32:09 by syboeuf           #+#    #+#             */
/*   Updated: 2018/04/04 12:52:24 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

t_room			*find_room(t_room **room, char *infos)
{
	t_room *tmp;

	tmp = *room;
	while (tmp != NULL)
	{
		if (ft_strcmp(infos, tmp->room2) == 0)
			return (tmp);
		tmp = tmp->next;
		if (tmp == NULL)
			ft_printf("");
	}
	return (NULL);
}

long long int	compute(t_links *tmp, t_infos *infos, t_room *in, t_room *room)
{
	t_room				*new;
	long long int		total_x;
	long long int		total_y;
	long long int		total_x_end;
	long long int		total_y_end;

	if (ft_strcmp(in->room2, tmp->l1) == 0)
		new = find_room(&room, tmp->l2);
	else
		new = find_room(&room, tmp->l1);
	if (!new || new->visited == 1)
		return (-1);
	total_x = in->x - new->x;
	total_x_end = new->x - infos->end.x;
	total_y = in->y - new->y;
	total_y_end = new->y - infos->end.y;
	total_x = (total_x < 0) ? -total_x : total_x;
	total_x_end = (total_x_end < 0) ? -total_x_end : total_x_end;
	total_y = (total_y < 0) ? -total_y : total_y;
	total_y_end = (total_y_end < 0) ? -total_y_end : total_y_end;
	infos->far = total_x + total_y + total_x_end + total_y_end;
	return (infos->far);
}

void			short_road2(t_infos *tmp2, t_links *tmp, t_room *room)
{
	tmp2->in->visited = 1;
	tmp2->flag = -1;
	while (tmp)
	{
		tmp2->total = compute(tmp, tmp2, tmp2->in, room);
		if (tmp2->total > 0 && tmp2->total <= tmp2->far2)
		{
			tmp2->flag = 0;
			tmp2->far2 = tmp2->total;
			ft_strdel(&tmp2->in_room);
			tmp2->in_room = (ft_strcmp(tmp2->in->room2, tmp->l1) == 0)
			? ft_strdup(tmp->l2) : ft_strdup(tmp->l1);
		}
		tmp = tmp->next;
	}
}

char			*short_road3(t_infos *tmp2, t_list **open)
{
	t_list *del;

	del = *open;
	*open = (*open)->next;
	ft_strdel((char**)&(del->content));
	del->next = NULL;
	free(del);
	if (*open == NULL)
		return (NULL);
	else
	{
		ft_strdel(&tmp2->in_room);
		return (ft_strdup((char*)(*open)->content));
	}
}

t_list			*short_road(t_infos *infos, t_room *room)
{
	t_links	*tmp;
	t_infos	*tmp2;
	t_list	*open;

	tmp2 = infos;
	tmp2->in_room = ft_strdup(tmp2->start.room2);
	open = NULL;
	while (42)
	{
		tmp2->far2 = 9223372036854775807;
		tmp2->in = find_room(&room, tmp2->in_room);
		tmp = tmp2->in->number;
		if (tmp2->in->visited != 1)
			ft_lstadd(&open, ft_lstnew(tmp2->in_room,
			ft_strlen(tmp2->in_room) + 1));
		if (ft_strcmp(tmp2->in->room2, tmp2->end.room2) == 0)
		{
			ft_strdel(&tmp2->in_room);
			return (open);
		}
		short_road2(tmp2, tmp, room);
		if (infos->flag == -1)
			if ((tmp2->in_room = short_road3(tmp2, &open)) == NULL)
				return (NULL);
	}
}
