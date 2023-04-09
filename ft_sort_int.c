/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echavez- <echavez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 14:37:20 by echavez-          #+#    #+#             */
/*   Updated: 2022/08/13 14:45:41 by echavez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int(int *tab, int size)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				k = tab[i];
				tab[i] = tab[j];
				tab[j] = k;
			}
			j++;
		}
		i++;
	}
}
