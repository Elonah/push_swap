/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 01:36:01 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/18 02:45:34 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*copie_tableau(t_pile *pile)
{
	int	i;
	int	j;
	int	*tab_int_copie;

	tab_int_copie = malloc(sizeof(int) * pile->size);
	if (!tab_int_copie)
		return (ft_error(1), free(pile->tab), NULL);
	i = -1;
	while (++i < pile->size)
		tab_int_copie[i] = pile->tab[i];
	return (tab_int_copie);
}

void	swap_int(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;

	i = 0;
	if (size < 2)
		return ;
	while (i < size - 1)
	{
		if (tab[i] > tab[i + 1])
			swap_int(tab + i, tab + i + 1);
		i++;
	}
	ft_sort_int_tab(tab, size -1);
}

int	find_median(t_pile *pile)
{
	int	*tab_int_copie;
	int	median;

	tab_int_copie = copie_tableau(pile);
	if (!tab_int_copie)
		exit(1);
	ft_sort_int_tab(tab_int_copie, pile->size);
	median = tab_int_copie[((pile->size) * 5) / 7];
	free (tab_int_copie);
	return (median);
}
