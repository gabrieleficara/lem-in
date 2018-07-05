/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 11:49:42 by syboeuf           #+#    #+#             */
/*   Updated: 2017/11/24 12:46:27 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int		count_letter(char const *s, char c, int i)
{
	int letter;

	letter = 0;
	while (s[i] != c && s[i] != '\0')
	{
		letter++;
		i++;
	}
	return (letter);
}

static int		count_words(char const *s, char c)
{
	int i;
	int count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static char		**ft_split(char **array, char const *s, char c)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		k = 0;
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			if (!(array[j] = (char*)malloc(sizeof(char)
							* (count_letter(s, c, i) + 1))))
				return (NULL);
			while (s[i] != c && s[i] != '\0')
				array[j][k++] = s[i++];
			array[j++][k] = '\0';
		}
	}
	array[j] = NULL;
	return (array);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	char	**array;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	if (!(array = (char**)malloc(sizeof(char*) * (count_words(s, c) + 1))))
		return (NULL);
	return (ft_split(array, s, c));
}
