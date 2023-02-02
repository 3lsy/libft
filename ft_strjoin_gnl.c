/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:55:20 by echavez-          #+#    #+#             */
/*   Updated: 2023/02/02 15:56:22 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char **s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*s;

	s1_len = ft_strlen(*s1);
	s2_len = ft_strlen(s2);
	s = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (s1_len > i)
	{
		s[i] = (*s1)[i];
		i++;
	}
	j = 0;
	while (s2_len > j)
		s[i++] = s2[j++];
	s[i] = 0;
	free(*s1);
	*s1 = NULL;
	return (s);
}
