/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_first.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:54:41 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/05 16:30:57 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_insert_first(t_doubly *new, t_doubly **start)
{
	t_doubly	*end;

	if (!new)
		return ;
	end = (*start)->prev;
	if (!(*start))
	{
		new->next = new;
		new->prev = new;
		*start = new;
		return ;
	}
	end->next = new;
	(*start)->prev = new;
	new->prev = end;
	new->next = *start;
	*start = new;
}
