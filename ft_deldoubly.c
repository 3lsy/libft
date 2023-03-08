/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deldoubly.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 22:59:00 by echavez-          #+#    #+#             */
/*   Updated: 2023/03/08 23:18:16 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_deldoubly(t_doubly **start)
{
	t_doubly	*tmp;
	t_doubly	*tmp2;
	t_doubly	*end;

	if (!*start)
		return ;
	end = (*start)->prev;
	end->next = NULL;
	tmp = *start;
	while (tmp)
	{
		tmp2 = tmp->next;
		free(tmp->obj);
		free(tmp);
		tmp = tmp2;
	}
	*start = NULL;
}
