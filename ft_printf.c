/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 20:41:16 by echavez-          #+#    #+#             */
/*   Updated: 2023/09/12 15:57:02 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	p_print(unsigned long x, int fd)
{
	int	counter;

	counter = 0;
	if (x == 0)
		counter += ft_putstr_fd("(nil)", fd);
	else
	{
		counter += ft_putstr_fd("0x", fd);
		counter += ft_uputnbr_base(x, LHEX, fd);
	}
	return (counter);
}

void	pconv(char conv, int fd, t_info	*x)
{
	int	*counter;

	counter = &x->counter;
	if (conv == 'd' || conv == 'i')
		*counter += ft_putnbr_base(va_arg(x->ap, int), DECIMAL, fd);
	else if (conv == '%')
		*counter += write(fd, "%", 1);
	else if (conv == 'c')
		*counter += ft_putchar_fd(va_arg(x->ap, int), fd);
	else if (conv == 's')
		*counter += ft_putstr_fd(va_arg(x->ap, char *), fd);
	else if (conv == 'x')
		*counter += ft_uputnbr_base(va_arg(x->ap, unsigned int), LHEX, fd);
	else if (conv == 'X')
		*counter += ft_uputnbr_base(va_arg(x->ap, unsigned int), UHEX, fd);
	else if (conv == 'u')
		*counter += ft_uputnbr_base(va_arg(x->ap, unsigned int), DECIMAL, fd);
	else if (conv == 'p')
		*counter += p_print(va_arg(x->ap, unsigned long), fd);
}

void	v_printf(const char *format, int fd, t_info *x)
{
	int	i;
	int	*counter;

	counter = &x->counter;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%' && ft_strchr(CONVERSIONS, format[i + 1]) != NULL)
			pconv(format[(i++) + 1], fd, x);
		else if (format[i] == '\\' && format[i + 1])
			*counter += write(fd, &format[i++], 2);
		else
			*counter += write(fd, &format[i], 1);
		i++;
	}
}

int	ft_printf(const char *format, ...)
{
	t_info	x;

	x.counter = 0;
	va_start(x.ap, format);
	v_printf(format, 1, &x);
	va_end(x.ap);
	return (x.counter);
}
