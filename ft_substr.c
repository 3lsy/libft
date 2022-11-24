/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 18:20:56 by echavez-          #+#    #+#             */
/*   Updated: 2022/11/20 19:21:47 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sbtr;
	char	*sbtr_copy;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (start > s_len)
		sbtr = malloc(sizeof(char));
	else if (s_len - start < len)
		sbtr = malloc((s_len - start + 1) * sizeof(char));
	else
		sbtr = malloc((len + 1) * sizeof(char));
	if (!sbtr)
		return (NULL);
	sbtr_copy = sbtr;
	while (start < s_len && len > 0 && s[start])
	{
		*(sbtr++) = s[start];
		start++;
		len--;
	}
	*sbtr = 0;
	return (sbtr_copy);
}
