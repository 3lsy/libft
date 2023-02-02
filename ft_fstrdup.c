/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fstrdup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 16:04:06 by echavez-          #+#    #+#             */
/*   Updated: 2023/02/02 16:04:21 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_fstrdup(char **fsrc, const char *src)
{
	int		i;
	int		lens;
	char	*cpy;

	lens = ft_strlen(src);
	cpy = malloc(sizeof(char) * (lens + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	free(*fsrc);
	*fsrc = NULL;
	return (cpy);
}
