/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:32:33 by syboeuf           #+#    #+#             */
/*   Updated: 2018/04/04 13:04:44 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	placing_x_y2(t_room *nb, char **array, int j)
{
	int k;

	k = 0;
	if (array[j])
	{
		while (array[j][k] != ' ')
			k++;
		while (array[j][k] == ' ')
			k++;
		nb->x = ft_atoi(array[j] + k);
		while (array[j][k] != ' ')
			k++;
		while (array[j][k] == ' ')
			k++;
		nb->y = ft_atoi(array[j] + k);
	}
}

void	placing_x_y(t_room *nb, char *new, char *tmp)
{
	char	**array;
	char	*s;
	int		j;

	array = ft_strsplit(new, '\n');
	j = -1;
	while (array[++j])
	{
		s = name_room(array[j]);
		if (ft_strcmp(tmp, s) == 0)
		{
			ft_strdel(&s);
			break ;
		}
		else
			ft_strdel(&s);
	}
	placing_x_y2(nb, array, j);
	freedoom(array);
}
