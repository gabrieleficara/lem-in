/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 12:32:38 by syboeuf           #+#    #+#             */
/*   Updated: 2018/04/04 13:04:22 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

void	read_array(t_infos *infos, char *file)
{
	char	**array;
	int		i;

	i = -1;
	array = ft_strsplit(file, '\n');
	while (array[++i])
	{
		if (ft_strstr(array[i], "##start"))
			start_and_end(infos, array, &infos->new, &i);
		if (ft_strchr(array[i], ' ') && !ft_strchr(array[i], '#'))
		{
			infos->new = ft_sfstrjoin(infos->new, array[i], 1);
			infos->new = ft_sfstrjoin(infos->new, "\n", 1);
			infos->count++;
		}
		if (ft_strstr(array[i], "##end"))
			start_and_end(infos, array, &infos->new, &i);
		if (ft_strchr(array[i], '-'))
		{
			infos->count_link++;
			infos->tmp = ft_sfstrjoin(infos->tmp, array[i], 1);
			infos->tmp = ft_sfstrjoin(infos->tmp, "\n", 1);
		}
	}
	freedoom(array);
}
