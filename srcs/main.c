/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:32:28 by syboeuf           #+#    #+#             */
/*   Updated: 2018/04/04 13:41:04 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int		count_list(t_list *final)
{
	int		i;

	i = 0;
	while (final)
	{
		i++;
		final = final->next;
	}
	return (i);
}

void	all_free(t_infos *infos, char **file, t_room *nb2)
{
	freed(&nb2);
	ft_strdel(&infos->tmp);
	ft_strdel(&infos->new);
	freedoom(infos->l);
	ft_strdel(&infos->start.room2);
	ft_strdel(&infos->end.room2);
	ft_strdel(file);
}

void	init(t_infos *infos)
{
	infos->count = 0;
	infos->count_link = 0;
	infos->tmp = ft_strdup("");
	infos->new = ft_strdup("");
}

int		main(void)
{
	t_room	*nb;
	t_infos	infos;
	t_room	*nb2;
	t_list	*final;
	char	*file;

	nb = NULL;
	file = NULL;
	if ((infos.n_ants = parsing(&file)) <= 0)
		return (0);
	init(&infos);
	read_array(&infos, file);
	infos.plus = infos.count + 2;
	infos.l = ft_strsplit(infos.tmp, '\n');
	nb2 = liste(&infos, nb, infos.new);
	final = short_road(&infos, nb2);
	if (final == NULL)
	{
		all_free(&infos, &file, nb2);
		return (error(NULL));
	}
	ft_printf("%s\n", file);
	walking_ants(&final, &nb2, infos);
	all_free(&infos, &file, nb2);
	return (0);
}
