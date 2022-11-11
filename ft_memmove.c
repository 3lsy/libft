/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:55:18 by echavez-          #+#    #+#             */
/*   Updated: 2022/11/11 21:04:15 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (*(unsigned char *)src > *(unsigned char *)dest)
	{
		i = -1;
		while (++i < n)
			*((unsigned char *)dest + i) = *((unsigned char *)src + i);
	}
	else
	{
		while (--n > 0)
			*((unsigned char *)dest + n) = *((unsigned char *)src + n);
	}
	return (dest);
}
