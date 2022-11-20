/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 17:56:05 by echavez-          #+#    #+#             */
/*   Updated: 2022/11/16 20:11:42 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *((t_byte *)s1 + i) == *((t_byte *)s2 + i))
		i++;
	if (i == n)
		return (0);
	return (*((t_byte *)s1 + i) - *((t_byte *)s2 + i));
}
