/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:38:36 by echavez-          #+#    #+#             */
/*   Updated: 2023/09/12 15:58:18 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_fprintf(int fd, const char *format, ...)
{
	t_info	x;

	x.counter = 0;
	va_start(x.ap, format);
	v_printf(format, fd, &x);
	va_end(x.ap);
	return (x.counter);
}
