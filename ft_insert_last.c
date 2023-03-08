/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insert_last.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 15:06:44 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/08 19:32:43 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_insert_last(t_doubly *new, t_doubly **start)
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
