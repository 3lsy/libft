/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:08:36 by echavez-          #+#    #+#             */
/*   Updated: 2023/02/11 22:15:38 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_args(char const *str, int count_args)
{
	int		i;
	char	quote;

	i = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i] && (str[i] == '\'' || str[i] == '\"'))
		{
			quote = str[i++];
			count_args++;
			while (str[i] && str[i] != quote)
				i++;
			if (str[i++] != quote)
				return (-1 * ft_putstr_fd("Inconsistent quote\n", 2));
		}
		else if (str[i] && !ft_isspace(str[i]))
		{
			count_args++;
			while (str[i] && !ft_isspace(str[i]))
				i++;
		}
	}
	return (count_args);
}

static char	*end_of_arg(const char *s, int *i, int j)
{
	char	quote;

	if (s[*i] == '\'' || s[*i] == '\"')
	{
		quote = s[(*i)++];
		while (s[*i] && s[*i] != quote)
			(*i)++;
		if (s[*i] == quote)
			(*i)++;
		return (ft_strndup(&s[j + 1], (*i) - j - 2));
	}
	while (s[*i] && !ft_isspace(s[*i]))
		(*i)++;
	return (ft_strndup(&s[j], (*i) - j));
}

char	**ft_split_args(const char *s)
{
	int		i;
	int		k;
	char	**tab;

	if (!s || ft_count_args(s, 0) < 0)
		return (NULL);
	tab = malloc((ft_count_args(s, 0) + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	k = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && ft_isspace(s[i]))
			i++;
		if (!s[i])
			continue ;
		tab[k++] = end_of_arg(s, &i, i);
	}
	tab[k] = NULL;
	return (tab);
}
