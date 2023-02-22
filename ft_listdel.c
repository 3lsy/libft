/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:32:33 by echavez-          #+#    #+#             */
/*   Updated: 2023/02/22 19:33:36 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_listdel(t_list **head)
{
	t_list	*tmp;

	if (head && *head)
	{
		tmp = *head;
		while (*head)
		{
			ft_putstr_fd("Deleting...", 2);
			ft_putstr_fd(((char *)(*head)->obj), 2);
			ft_putstr_fd("\n", 2);
			tmp = *head;
			*head = tmp->next;
			free(tmp->obj);
			tmp->obj = NULL;
			free(tmp);
			tmp = NULL;
		}
	}
}
