/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:55:18 by echavez-          #+#    #+#             */
/*   Updated: 2022/11/16 19:55:45 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (*(t_byte *)src > *(t_byte *)dest)
	{
		i = -1;
		while (++i < n)
			*((t_byte *)dest + i) = *((t_byte *)src + i);
	}
	else
	{
		while (n > 0)
		{
			n--;
			*((t_byte *)dest + n) = *((t_byte *)src + n);
		}
	}
	return (dest);
}
