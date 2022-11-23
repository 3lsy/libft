/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:51:03 by echavez-          #+#    #+#             */
/*   Updated: 2022/11/23 17:37:39 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	from_str(char const *s1, char c)
{
	size_t	i;

	i = 0;
	while (s1[i])
	{
		if (s1[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	trim_size(char const *s1, char const *set, size_t *i, size_t *j)
{
	size_t	count;

	*i = 0;
	while (s1[*i] && from_str(set, s1[*i]))
		(*i)++;
	*j = ft_strlen(s1) - 1;
	while (*j != 0 && from_str(set, s1[*j]))
		(*j)--;
	count = *i + (ft_strlen(s1) - 1 - *j);
	if (*i == *j)
		return (1);
	if (*i > *j)
		return (0);
	return (ft_strlen(s1) - count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*new;
	int		new_i;

	new = malloc((trim_size(s1, set, &i, &j) + 1) * sizeof(char));
	if (!new)
		return (NULL);
	new_i = 0;
	while (s1[new_i] && i <= j)
		new[new_i++] = s1[i++];
	new[new_i] = 0;
	return (new);
}
