/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: syboeuf <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 12:47:43 by syboeuf           #+#    #+#             */
/*   Updated: 2018/03/29 14:42:47 by syboeuf          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*array;

	array = (t_list*)malloc(sizeof(t_list));
	if (array == NULL)
		return (NULL);
	if (content == NULL)
	{
		array->content = NULL;
		array->content_size = 0;
	}
	else
	{
		if (!(array->content = malloc(content_size + 1)))
			return (NULL);
		ft_memcpy(array->content, content, content_size);
		array->content_size = content_size;
	}
	array->next = NULL;
	return (array);
}
