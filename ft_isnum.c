/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 22:06:22 by echavez-          #+#    #+#             */
/*   Updated: 2023/12/15 16:07:21 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnum(char *nb)
{
	int	i;

	if (!nb)
		return (0);
	i = 0;
	if (nb[0] == '-' || nb[0] == '+')
	{
		if (!nb[1] || !ft_isdigit(nb[1]))
			return (0);
		i++;
	}
	while (nb[i] && ft_isdigit(nb[i]))
		i++;
	if (nb[i])
		return (0);
	return (1);
}
