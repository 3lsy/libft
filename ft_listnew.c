/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 19:33:05 by echavez-          #+#    #+#             */
/*   Updated: 2023/02/22 19:33:10 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_listnew(void *content, size_t size)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	if (content)
	{
		new->obj = content;
		new->size = size;
	}
	else
	{
		new->obj = NULL;
		new->size = 0;
	}
	new->next = NULL;
	return (new);
}
