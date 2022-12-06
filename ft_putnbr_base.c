/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:09:08 by echavez-          #+#    #+#             */
/*   Updated: 2022/12/05 23:30:10 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_valid_base(char *base)
{
	int	i;
	int	j;

	if (!base || !base[0] || !base[1])
		return (0);
	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] <= 32 || base[i] > 126)
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base [j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int		i;
	int		size;
	char	res[42];
	long	num;
	int		written;

	num = (long)nbr;
	if (!ft_is_valid_base(base))
		return (-1);
	if (num < 0)
	{
		write(1, "-", 1);
		num = -num;
	}
	size = ft_strlen(base);
	i = 0;
	while (num)
	{
		res[i++] = base[num % size];
		num = num / size;
	}
	written = i + (nbr < 0);
	while (i > 0)
		write(1, &res[--i], 1);
	return (written);
}
