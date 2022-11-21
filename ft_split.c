/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 20:36:09 by echavez-          #+#    #+#             */
/*   Updated: 2022/11/21 09:44:47 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *str, char c)
{
	int	i;
	int	count_words;

	i = 0;
	count_words = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i] && str[i] != c)
		{
			count_words++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count_words);
}

char	*ft_strndup(char const *src, int size)
{
	int		i;
	int		lens;
	char	*cpy;

	lens = ft_strlen(src);
	if (lens > size)
		lens = size;
	cpy = malloc(sizeof(char) * (lens + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (src[i] && i < size)
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

char	**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	if (!s)
		return (NULL);
	tab = malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	k = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (!(s[i] && s[i] != c))
			continue ;
		j = i;
		while (s[i] && s[i] != c)
			i++;
		tab[k++] = ft_strndup(&s[j], i - j);
	}
	tab[k] = NULL;
	return (tab);
}
