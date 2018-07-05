/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_fonction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:06:20 by syboeuf           #+#    #+#             */
/*   Updated: 2018/04/04 08:50:11 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_strdel(char **as)
{
	if (as == NULL)
		return ;
	free(*as);
	*as = NULL;
}

int		ft_strchrtab(const char *s, const char *s2)
{
	int i;
	int j;

	i = 0;
	while (s[i])
	{
		j = 0;
		while (s2[j])
		{
			if (s[i] == s2[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	int i;

	i = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

void	ft_putchar(int c, t_p *p)
{
	write(1, &c, 1);
	p->total++;
}

void	ft_putstr(char const *s, t_p *p)
{
	int i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar(s[i], p);
		i++;
	}
}
