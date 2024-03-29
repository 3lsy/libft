/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprintable.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 20:22:37 by echavez-          #+#    #+#             */
/*   Updated: 2023/09/14 20:32:42 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprintable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isprint(str[i]))
			return (0);
		i++;
	}
	return (1);
}
