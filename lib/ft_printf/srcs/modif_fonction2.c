/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   modif_fonction2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 15:07:32 by syboeuf           #+#    #+#             */
/*   Updated: 2018/02/14 16:40:35 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_putnbr(long long int n, t_p *p)
{
	int nombre;

	nombre = 0;
	if (n == -2147483648)
		ft_putstr("2147483648", p);
	else if (n < 0)
	{
		ft_putchar('-', p);
		n = n * -1;
	}
	if (n == 0)
		ft_putchar('0', p);
	if (n >= 1)
	{
		nombre = n % 10 + '0';
		if ((n / 10) != 0)
			ft_putnbr(n / 10, p);
		ft_putchar(nombre, p);
	}
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	letter;
	size_t			i;

	i = 0;
	letter = c;
	while (i <= ft_strlen(s))
	{
		if (s[i] == letter)
			return ((char *)(s + i));
		i++;
	}
	return (0);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	int		i;

	i = 0;
	if (!(dest = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	while (s[i] != '\0')
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		width_int(char c, unsigned int nombre)
{
	int i;
	int j;

	j = 10;
	if (c == 'o' || c == 'O')
		j = 8;
	else if (c == 'x' || c == 'X')
		j = 16;
	i = 0;
	while ((nombre = nombre / j) != 0)
		i++;
	return (i);
}
