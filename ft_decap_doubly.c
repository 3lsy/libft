/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decap_doubly.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 18:43:59 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/09 19:51:45 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_decap_doubly(t_doubly **start)
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
	end->next = (*start)->next;
	(end->next)->prev = end;
	free((*start)->obj);
	free(*start);
	*start = end->next;
}
