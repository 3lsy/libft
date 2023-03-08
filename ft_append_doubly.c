/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append_doubly.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 23:03:01 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/08 23:03:06 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_append_doubly(t_doubly *new, t_doubly **start)
{
	t_doubly	*end;

	if (!new)
		return ;
	if (!*start)
	{
		new->next = new;
		new->prev = new;
		*start = new;
		return ;
	}
	end = (*start)->prev;
	end->next = new;
	(*start)->prev = new;
	new->prev = end;
	new->next = *start;
}
