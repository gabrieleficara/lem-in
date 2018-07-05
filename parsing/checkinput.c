/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkinput.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gficara <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/03 09:46:37 by gficara           #+#    #+#             */
/*   Updated: 2018/04/04 12:57:33 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lemin.h"

int	findname(char *str, char *file)
{
	int		len;
	char	*decoy;

	len = ft_strlen(str);
	if (!strncmp(file, str, len))
		file = file + len;
	while (file)
	{
		if (!(decoy = ft_strstr(file, str)))
			return (0);
		if (decoy[-1] == '\n')
			if (decoy[len] && decoy[len] == ' ')
				return (1);
		file = file + len;
	}
	return (0);
}

int	repeated(char *str, char *file)
{
	char	*new;
	int		i;

	i = 0;
	while (str[i] && str[i] != ' ')
		i++;
	new = ft_strsub(str, 0, i);
	if (findname(new, file))
	{
		ft_strdel(&new);
		return (1);
	}
	ft_strdel(&new);
	return (0);
}

int	linkstr(char *str, char *file, int *error)
{
	int		i;
	int		flag;
	char	**tab;

	if (*error == 1)
		return ((*error = -1));
	i = 0;
	flag = 1;
	while (str[i] && str[i] != '-')
		i++;
	if (!str[i++])
		return (-1);
	while (str[i] && str[i] != '-')
		i++;
	if (str[i])
		return (-1);
	tab = ft_strsplit(str, '-');
	if (!findname(tab[0], file) || !findname(tab[1], file))
		flag = -1;
	ft_strdel(tab);
	ft_strdel(tab + 1);
	free(tab);
	return (flag);
}

int	checkse(char **str, t_data *data, int *flag, int i)
{
	if (!ft_strcmp(*str, "") && i == 0)
		return (error(str));
	if (!ft_strncmp(*str, "#", 1) && *flag != 0)
		return (error(str));
	if (!ft_strcmp(*str, "##start"))
	{
		data->start++;
		*flag = 1;
	}
	if (!ft_strcmp(*str, "##end"))
	{
		data->end++;
		*flag = 1;
	}
	if (data->start > 1 || data->end > 1)
		return (error(str));
	return (0);
}

int	b_obt(char **file, t_data *data, int *i, int *flag)
{
	char	*str;

	*i = 0;
	*flag = 0;
	if ((data->ants = (noants(&str, data->fd, 1, i))) <= 0)
		return (error(&str));
	*file = ft_strdup(str);
	ft_strdel(&str);
	return (0);
}
