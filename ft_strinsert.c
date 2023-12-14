/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:19:24 by echavez-          #+#    #+#             */
/*   Updated: 2023/12/14 19:12:47 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	char_str(char **str, char c)
{
	*str = ft_strnew(1);
	(*str)[0] = c;
}

void	ft_strinserts(char **str, char *s, size_t index)
{
	char	*new;
	size_t	len;

	if (!str)
		return ;
	if (!*str)
		return (char_str(str, *s));
	if (!s)
		s = "";
	len = ft_strlen(*str);
	if (index > len)
	{
		free(*str);
		*str = NULL;
		return ;
	}
	new = ft_strnew(len + ft_strlen(s) + 1);
	if (!new)
		return ;
	ft_strcpy(new, *str);
	ft_strcpy(new + index, s);
	ft_strcpy(new + index + ft_strlen(s), *str + index);
	free(*str);
	*str = new;
}

void	ft_strinsert(char **str, char c, size_t index)
{
	char	*new;
	size_t	len;

	if (!str)
		return ;
	if (!*str)
		return (char_str(str, c));
	len = ft_strlen(*str);
	if (index > len)
	{
		free(*str);
		*str = NULL;
		return ;
	}
	new = ft_strnew(len + 2);
	if (!new)
		return ;
	ft_strcpy(new, *str);
	new[index] = c;
	ft_strcpy(new + index + 1, *str + index);
	free(*str);
	*str = new;
}
