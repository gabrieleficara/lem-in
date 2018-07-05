/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stock.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:32:52 by syboeuf           #+#    #+#             */
/*   Updated: 2018/04/04 13:12:11 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	start(t_infos *infos, char *line, int i)
{
	infos->start.room2 = name_room(line);
	while (line[i] && line[i] != ' ')
		i++;
	i++;
	infos->start.x = ft_atoi(line + i);
	while (line[i] && line[i] != ' ')
		i++;
	i++;
	infos->start.y = ft_atoi(line + i);
}

void	start_and_end(t_infos *infos, char **line, char **new, int *j)
{
	int i;
	int b;

	b = 0;
	if (ft_strstr(line[*j], "##start"))
		b = 1;
	i = 0;
	(*j)++;
	*new = ft_sfstrjoin(*new, line[*j], 1);
	*new = ft_sfstrjoin(*new, "\n", 1);
	if (b == 1)
	{
		start(infos, line[*j], i);
		return ;
	}
	infos->end.room2 = name_room(line[*j]);
	while (line[*j][i] && line[*j][i] != ' ')
		i++;
	i++;
	(infos->end).x = ft_atoi(line[*j] + i);
	while (line[*j][i] && line[*j][i] != ' ')
		i++;
	i++;
	(infos->end).y = ft_atoi(line[*j] + i);
}

void	test(t_infos *infos, char **tmp, int i)
{
	infos->k = -1;
	infos->a = 0;
	while (tmp[i][++infos->k])
		if (tmp[i][infos->k] == '-')
			break ;
	if (!(infos->tmp1 = (char*)malloc(sizeof(char) * infos->k++ + 1)))
		return ;
	while (tmp[i][infos->a + infos->k])
		infos->a++;
	if (!(infos->tmp2 = (char*)malloc(sizeof(char) * infos->a + 1)))
		return ;
	infos->k = -1;
	while (tmp[i][++infos->k])
	{
		if (tmp[i][infos->k] == '-')
			break ;
		infos->tmp1[infos->k] = tmp[i][infos->k];
	}
	infos->tmp1[infos->k++] = '\0';
	infos->a = 0;
	while (tmp[i][infos->k])
		infos->tmp2[infos->a++] = tmp[i][infos->k++];
	infos->tmp2[infos->a] = '\0';
}

void	liste2(t_infos *infos, int j, t_room *nb, char *tmp)
{
	test(infos, infos->l, j);
	if ((ft_strcmp(tmp, infos->tmp1) == 0)
	|| (ft_strcmp(tmp, infos->tmp2) == 0))
		addlink(nb, infos->tmp1, infos->tmp2);
	else
	{
		ft_strdel(&infos->tmp1);
		ft_strdel(&infos->tmp2);
	}
}

t_room	*liste(t_infos *infos, t_room *nb, char *new)
{
	int		i;
	int		j;
	char	**array;
	char	*tmp;

	array = ft_strsplit(new, '\n');
	i = -1;
	while (++i < infos->plus)
	{
		tmp = name_room(array[i]);
		addroom(&nb, i, tmp);
		j = -1;
		placing_x_y(nb, new, tmp);
		while (++j < infos->count_link)
			liste2(infos, j, nb, tmp);
		ft_strdel(&tmp);
	}
	freedoom(array);
	return (nb);
}
