/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:52:34 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/05 14:53:04 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_doubly	*ft_create_node(void *content, size_t size)
{
	t_doubly	*new;

	new = malloc(sizeof(t_doubly));
	if (!new)
		return (NULL);
	if (content)
	{
		new->obj = content;
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
