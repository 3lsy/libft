/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 23:09:08 by echavez-          #+#    #+#             */
/*   Updated: 2023/09/12 15:33:43 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(int nbr, char *base, int fd)
{
	int		i;
	int		size;
	char	res[42];
	long	num;
	int		written;

	if (nbr == 0)
		return (write(fd, "0", 1));
	num = (long)nbr;
	if (num < 0)
	{
		write(fd, "-", 1);
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
		write(fd, &res[--i], 1);
	return (written);
}
