/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:10:08 by echavez-          #+#    #+#             */
/*   Updated: 2023/12/13 19:57:01 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The strchr() function locates the first occurrence of c (converted to a char)
** if it is found in the string pointed to by s.
** If c is not found, NULL is returned.
*/

char	*ft_strchr(const char *s, int c)
{
	int	i;

	c = (char)c;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)(&s[i]));
		i++;
	}
	if (c == '\0')
		return ((char *)(&s[i]));
	return (NULL);
}
