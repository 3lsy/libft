/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pop_doubly.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:44:39 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/09 19:51:31 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_pop_doubly(t_doubly **start)
{
	t_doubly	*end;

	if (!*start)
		return ;
	end = (*start)->prev;
	if (*start == end)
	{
		free((*start)->obj);
		free(*start);
		*start = NULL;
		return ;
	}
	(*start)->prev = end->prev;
	((*start)->prev)->next = *start;
	free(end->obj);
	free(end);
}
