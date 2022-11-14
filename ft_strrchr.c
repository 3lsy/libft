/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:40:15 by echavez-          #+#    #+#             */
/*   Updated: 2022/11/14 18:53:54 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	s_len;
	size_t	i;

	s_len = ft_strlen(s);
	i = s_len - 1;
	while (i < 0)
	{
		if (s[i] == c)
			return ((char *)(&s[i]));
		i--;
	}
	if (c == '\0')
		return ((char *)(&s[s_len - 1]));
	return (NULL);
}
