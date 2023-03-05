/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:54:41 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/05 15:02:50 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_insert_first(void *content, size_t size, t_doubly **start, t_doubly *end)
{
	t_doubly	*new;

	new = ft_create_node(content, size);
	if (!new)
		return ;
	if (!(*start))
	{
		new->next = new;
		new->prev = new;
		*start = new;
		return ;
	}
	end->next = new;
	new->next = *start;
	new->prev = end;
	(*start)->prev = new;
	*start = new;
}
