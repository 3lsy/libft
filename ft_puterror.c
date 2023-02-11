/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 18:19:30 by echavez-          #+#    #+#             */
/*   Updated: 2023/02/11 18:32:16 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puterror(char *start, char *cmd, char *end)
{
	int	ret;

	ret = 0;
	ret += ft_putstr_fd(start, 2);
	ret += ft_putstr_fd(": ", 2);
	ret += ft_putstr_fd(cmd, 2);
	ret += ft_putstr_fd(": ", 2);
	ret += ft_putstr_fd(end, 2);
	ret += ft_putstr_fd("\n", 2);
	return (ret);
}
