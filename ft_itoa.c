/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 22:56:42 by echavez-          #+#    #+#             */
/*   Updated: 2023/06/20 22:42:39 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long nb)
{
	size_t	i;

	i = 0;
	while (nb != 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

long	ft_abs(long nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

char	*ft_itoa(int n)
{
	int		i;
	long	nb;
	char	*ret;
	size_t	n_len;

	if (n == 0)
		return (ft_strdup("0"));
	nb = n;
	n_len = ft_intlen(nb);
	ret = malloc((n_len + (nb < 0) + 1) * sizeof(char));
	if (!ret)
		return (NULL);
	i = n_len + (nb < 0);
	while (i-- > 0)
	{
		ret[i] = (char)(ft_abs(nb % 10) + '0');
		nb /= 10;
	}
	if (n < 0)
		ret[0] = '-';
	ret[n_len + (n < 0)] = 0;
	return (ret);
}
