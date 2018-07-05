/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 14:59:31 by syboeuf           #+#    #+#             */
/*   Updated: 2018/03/13 13:46:58 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		search_new_line(char **save, char **line, t_ligne ligne)
{
	int		i;
	char	*array;

	i = 0;
	ligne.stock = *save;
	while (ligne.stock[i] != '\n')
		if (!ligne.stock[i++])
			return (0);
	array = &ligne.stock[i];
	*array = '\0';
	*line = ft_strdup(*save);
	*save = ft_strdup(array + 1);
	ft_strdel(&ligne.stock);
	return (1);
}

int		read_file(int fd, char **save, char **line, t_ligne ligne)
{
	int i;

	while ((i = read(fd, ligne.array, BUFF_SIZE)) > 0)
	{
		ligne.array[i] = '\0';
		if (*save)
		{
			ligne.tab = *save;
			*save = ft_strjoin(ligne.tab, ligne.array);
			ft_strdel(&ligne.tab);
		}
		else
			*save = ft_strdup(ligne.array);
		if (search_new_line(save, line, ligne))
			break ;
	}
	ft_strdel(&ligne.array);
	i = i > 0 ? 1 : i;
	return (i);
}

int		get_next_line(const int fd, char **line)
{
	static char		*save[MAX_FD];
	t_ligne			ligne;

	if ((fd < 0 || fd > MAX_FD) || !line || (read(fd, save[fd], 0) < 0)
			|| !(ligne.array = (char*)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (-1);
	if (save[fd])
		if (search_new_line(&save[fd], line, ligne))
		{
			ft_strdel(&ligne.array);
			return (1);
		}
	ligne.i = read_file(fd, &save[fd], line, ligne);
	if (ligne.i != 0 || save[fd] == NULL || save[fd][0] == '\0')
	{
		if (!ligne.i && *line)
		{
			*line = NULL;
			ft_strdel(&save[fd]);
		}
		return (ligne.i);
	}
	*line = save[fd];
	save[fd] = NULL;
	return (1);
}
