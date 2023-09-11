/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k24.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:53:53 by echavez-          #+#    #+#             */
/*   Updated: 2023/09/11 17:53:56 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	k =  24
**	char		**tab = (char **)calloc(16777213, sizeof(char *));
**	tab[hash(line)] = "str"
*/

unsigned int	k24(const char *key)
{
	unsigned int	hash;

	hash = 5031;
	while (*key)
		hash = (hash * 101) + *key++;
	return (hash % 16777213);
}