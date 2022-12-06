/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uputnbr_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 01:48:51 by echavez-          #+#    #+#             */
/*   Updated: 2022/12/06 02:52:02 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "libft.h"

uintmax_t	ft_uputnbr_base(uintmax_t nbr, char *base)
{
	uintmax_t		i;
	uintmax_t		size;
	char			res[42];
	uintmax_t		written;

	size = ft_strlen(base);
	i = 0;
	while (nbr)
	{
		res[i++] = base[nbr % size];
		nbr = nbr / size;
	}
	written = i;
	while (i != 0)
		write(1, &res[--i], 1);
	return (written);
}
