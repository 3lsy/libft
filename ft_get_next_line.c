/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:56:43 by echavez-          #+#    #+#             */
/*   Updated: 2023/02/05 14:27:41 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_fill_buffer(char **buffer, int fd)
{
	char	*buffy;
	int		end;

	buffy = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffy || fd < 0 || BUFFER_SIZE < 1)
	{
		free(buffy);
		return (0);
	}
	if (*buffer == NULL)
		*buffer = ft_strdup("");
	buffy[0] = 0;
	while (ft_strchr_pos(buffy, '\n') == -1)
	{
		end = read(fd, buffy, BUFFER_SIZE);
		if (end <= 0)
			break ;
		buffy[end] = 0;
		*buffer = ft_strjoin_gnl(buffer, buffy);
	}
	free(buffy);
	if (end < 0)
		return (0);
	return (1);
}

char	*ft_get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	int			enter;

	if (!ft_fill_buffer(&buffer, fd))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	enter = ft_strchr_pos(buffer, '\n');
	if (enter >= 0)
	{
		line = ft_strdup(buffer);
		line[enter + 1] = 0;
		buffer = ft_fstrdup(&buffer, &buffer[enter + 1]);
		return (ft_fstrdup(&line, line));
	}
	if (buffer[0] == 0)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	return (ft_fstrdup(&buffer, buffer));
}
