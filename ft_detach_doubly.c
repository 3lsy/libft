/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_detach_doubly.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 20:01:28 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/17 20:06:26 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_detach_doubly(t_doubly **start)
{
	t_doubly	*end;

	if (!*start)
		return ;
	end = (*start)->prev;
	if (*start == end)
	{
		*start = NULL;
		return ;
	}
	end->next = (*start)->next;
	(end->next)->prev = end;
	*start = end->next;
}
