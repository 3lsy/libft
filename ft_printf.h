/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/26 14:39:06 by echavez-          #+#    #+#             */
/*   Updated: 2023/09/12 16:04:14 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "libft.h"

# define CONVERSIONS "dicsupxX%"
# define DECIMAL "0123456789"
# define LHEX "0123456789abcdef"
# define UHEX "0123456789ABCDEF"

typedef struct s_info {
	int		counter;
	va_list	ap;
}	t_info;

int		ft_printf(const char *format, ...)
		__attribute__((format(printf, 1, 2)));

int		ft_fprintf(int fd, const char *format, ...)
		__attribute__((format(printf, 2, 3)));

void	v_printf(const char *format, int fd, t_info *x);

#endif
