/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 15:56:43 by echavez-          #+#    #+#             */
/*   Updated: 2023/06/24 00:25:54 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strjoin_gnl(char **s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*s;

	s1_len = ft_strlen(*s1);
	s2_len = ft_strlen(s2);
	s = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (s1_len > i)
	{
		s[i] = (*s1)[i];
		i++;
	}
	j = 0;
	while (s2_len > j)
		s[i++] = s2[j++];
	s[i] = 0;
	free(*s1);
	*s1 = NULL;
	return (s);
}

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

/*
** Send a fd of -503 for freeing the buffer
** if exiting before the EOF
*/

char	*ft_get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	int			enter;

	if (fd == -503 || !ft_fill_buffer(&buffer, fd))
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	enter = ft_strchr_pos(buffer, '\n');
	if (enter >= 0)
	{
		line = ft_strdup(buffer);
		line[enter] = 0;
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
