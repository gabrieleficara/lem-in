/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 10:31:43 by syboeuf           #+#    #+#             */
/*   Updated: 2017/11/15 10:04:24 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	*ft_memalloc(size_t size)
{
	void	*array;

	array = (void*)malloc(sizeof(size_t) * (size));
	if (array == NULL)
		return (NULL);
	ft_bzero(array, size);
	return (array);
}
