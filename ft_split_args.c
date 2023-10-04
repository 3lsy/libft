/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 14:08:36 by echavez-          #+#    #+#             */
/*   Updated: 2023/10/04 00:38:44 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	read_arg(char const *str, int i, char *quote)
{
	while (str[i] && !ft_isspace(str[i])
		&& str[i] != '\'' && str[i] != '\"')
		i++;
	if (str[i] == '\'' || str[i] == '\"')
	{
		*quote = str[i++];
		while (str[i] && str[i] != *quote)
			i++;
		if (str[i++] != *quote)
			return (-1);
	}
	return (i);
}

static int	ft_count_args(char const *str, int count_args)
{
	int		i;
	char	quote;

	i = 0;
	while (str[i])
	{
		while (str[i] && ft_isspace(str[i]))
			i++;
		if (str[i])
			count_args++;
		while (str[i] && !ft_isspace(str[i]))
		{
			i = read_arg(str, i, &quote);
			if (i < 0)
			{
				errno = EINVAL;
				return (-1);
			}
		}
	}
	return (count_args);
}

static char	*end_of_arg(const char *s, int *i, int j)
{
	char	quote;

	while (s[*i] && !ft_isspace(s[*i]))
	{
		while (s[*i] && !ft_isspace(s[*i])
			&& s[*i] != '\'' && s[*i] != '\"')
			(*i)++;
		if (s[*i] == '\'' || s[*i] == '\"')
		{
			quote = s[(*i)++];
			while (s[*i] && s[*i] != quote)
				(*i)++;
			(*i) += (s[*i] == quote);
		}
		else
			break ;
	}
	return (ft_strndup(&s[j], (*i) - j));
}

static void	fill_tab(char **tab, const char *s)
{
	int		i;
	int		k;

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
}

char	**ft_split_args(const char *s)
{
	int		size;
	char	**tab;

	if (!s)
		return (NULL);
	size = ft_count_args(s, 0);
	if (size < 0)
		return (NULL);
	tab = malloc((size + 1) * sizeof(char *));
	if (!tab)
		return (NULL);
	fill_tab(tab, s);
	return (tab);
}
