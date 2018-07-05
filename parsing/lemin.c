/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/30 13:21:50 by gficara           #+#    #+#             */
/*   Updated: 2018/04/04 13:00:53 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int	error(char **str)
{
	if (str)
		ft_strdel(str);
	return (ft_printf("ERROR\n"));
}

int	noants(char **str, int fd, int flag, int *j)
{
	int		ants;
	int		i;

	if (flag == 1)
	{
		i = 0;
		if (get_next_line(fd, str) <= 0)
			return (-1);
		if ((ants = ft_atoi(*str)) <= 0)
			return (0);
		while ((*str)[i] && (*str)[i] >= '0' && (*str)[i] <= '9')
			i++;
		if (!(*str)[i])
			return (ants);
		else
			return (0);
	}
	(*j)++;
	if ((*str)[*j] == '-')
		(*j)++;
	if ((*str)[*j] == ' ')
		return (1);
	return (0);
}

int	roomstr(char **str, int *flag, char *file)
{
	int		i;

	i = 0;
	*flag = 0;
	if (!ft_strncmp(*str, "L", 1))
		return (error(str));
	while ((*str)[i] != '\0' && (*str)[i] != ' ')
		i++;
	if ((*str)[i] == '\0')
		return (error(str));
	if (coor_check(*str + i, file))
		return (error(str));
	if (noants(str, i, 0, &i))
		return (error(str));
	while ((*str)[i] >= '0' && (*str)[i] <= '9')
		i++;
	if ((*str)[i] != ' ')
		return (error(str));
	if (noants(str, i, 0, &i))
		return (error(str));
	while ((*str)[i] >= '0' && (*str)[i] <= '9')
		i++;
	if ((*str)[i] != '\0' || repeated(*str, file))
		return (error(str));
	return (0);
}

int	obtain(char **file, t_data *data)
{
	char	*str;
	int		i;
	int		flag;

	if (b_obt(file, data, &i, &flag) > 0)
		return (2);
	while (i >= 0 && get_next_line(data->fd, &str) > 0)
	{
		*file = ft_sfstrjoin(*file, "\n", 1);
		if (checkse(&str, data, &flag, i))
			return (1);
		if (ft_strncmp(str, "#", 1) && (i == 0 && ft_strchr(str, ' ')))
		{
			if (roomstr(&str, &flag, *file) && data->n_room++ >= 0)
				return (1);
		}
		else if (ft_strncmp(str, "#", 1) && (i > 0 || ft_strchr(str, '-')))
			i = linkstr(str, *file, &flag);
		if (i >= 0)
			*file = ft_sfstrjoin(*file, str, 1);
		ft_strdel(&str);
	}
	if (i >= 0)
		*file = ft_sfstrjoin(*file, "\n", 1);
	return ((flag != 0 || data->start == 0 || data->end == 0) ? error(0) : 0);
}

int	parsing(char **file)
{
	t_data	data;
	int		i;

	data.start = 0;
	data.end = 0;
	data.n_room = 0;
	data.fd = 0;
	if ((i = obtain(file, &data)) > 0)
	{
		if (*file && i == 1)
			ft_strdel(file);
		return (0);
	}
	if (*file)
		return (data.ants);
	return (0);
}
