/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:52:34 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/08 14:13:32 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_doubly	*ft_create_node(void *content, size_t size)
{
	t_doubly	*new;

	new = (t_doubly*)malloc(sizeof(t_doubly));
	if (!new)
		return (NULL);
	if (content)
	{
		new->obj = (void*)malloc(sizeof(void) * (size + 1));
		if (!(new->obj))
			return (NULL);
		ft_memcpy(new->obj, content, size);
		new->size = size;
	}
	else
	{
		new->obj = NULL;
		new->size = 0;
	}
	new->next = NULL;
	new->prev = NULL;
	return (new);
}
