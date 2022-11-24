/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 17:57:00 by echavez-          #+#    #+#             */
/*   Updated: 2022/11/16 17:53:00 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	size_t	i;

	i = -1;
	while (++i < n)
	{
		*((t_byte *)dest + i) = *((t_byte *)src + i);
	}
	return (dest);
}
