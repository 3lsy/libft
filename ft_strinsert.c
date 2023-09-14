/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 19:19:24 by echavez-          #+#    #+#             */
/*   Updated: 2023/09/14 22:52:31 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	char_str(char **str, char c)
{
	*str = ft_strnew(1);
	(*str)[0] = c;
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
