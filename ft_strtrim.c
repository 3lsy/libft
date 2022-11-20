/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:51:03 by echavez-          #+#    #+#             */
/*   Updated: 2022/11/20 20:29:22 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count(char const *s1, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			count++;
		i++;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	size_t	c_set;
	size_t	i;
	char	*s;
	char	*s_copy;

	s1_len = ft_strlen(s1);
	c_set = 0;
	i = 0;
	while (set[i])
		c_set += ft_count(s1, set[i++]);
	s = malloc((s1_len - c_set + 1) * sizeof(char));
	if (!s)
		return (NULL);
	s_copy = s;
	i = 0;
	while (i < s1_len && s1[i])
	{
		if (ft_count(set, s1[i]) == 0)
			*(s++) = s1[i];
		i++;
	}
	*s = 0;
	return (s_copy);
}
