/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 19:22:35 by echavez-          #+#    #+#             */
/*   Updated: 2023/09/14 22:01:30 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	**ft_gstrjoin(char *gstrjoin)
{
	static t_list	*head = NULL;
	t_list			*tmp;

	if (gstrjoin)
	{
		if (!head)
		{
			head = ft_listnew(gstrjoin, sizeof(gstrjoin));
			if (!head)
				return (NULL);
			return (&head);
		}
		tmp = head;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_listnew(gstrjoin, sizeof(gstrjoin));
		if (!tmp->next)
		{
			ft_listdel(&head);
			return (NULL);
		}
	}
	else if (!gstrjoin && !head)
		return (NULL);
	return (&head);
}

void	ft_freejoin(char **str)
{
	t_list	*tmp;

	tmp = *ft_gstrjoin(NULL);
	while (tmp)
	{
		if ((char *)tmp->obj == *str)
		{
			free(tmp->obj);
			tmp->obj = NULL;
			*str = NULL;
			break ;
		}
		tmp = tmp->next;
	}
}

char	*ft_strjoin(char const *s1, char const *s2, int collect)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;
	size_t	j;
	char	*s;

	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	s = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (!s)
		return (NULL);
	i = 0;
	while (s1_len > i)
	{
		s[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2_len > j)
		s[i++] = s2[j++];
	s[i] = 0;
	if (collect)
		ft_gstrjoin(s);
	return (s);
}

// priority number ++ global in library
static __attribute__((destructor)) void	del_strjoin(void)
{
	ft_listdel(ft_gstrjoin(NULL));
}
