/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:32:33 by echavez-          #+#    #+#             */
/*   Updated: 2023/02/22 19:36:34 by ciglesia         ###   ########.fr       */
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
			tmp = *head;
			*head = tmp->next;
			free(tmp->obj);
			tmp->obj = NULL;
			free(tmp);
			tmp = NULL;
		}
	}
}
