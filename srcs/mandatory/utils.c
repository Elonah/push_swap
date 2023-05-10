/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 01:50:52 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/20 22:44:48 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_index_of_min(t_pile *pile)
{
	int	min;
	int	i;
	int	index;

	min = pile->tab[0];
	i = 0;
	index = 0;
	while (++i < pile->size)
	{
		if (min > pile->tab[i])
		{
			min = pile->tab[i];
			index = i;
		}
	}
	return (index);
}

int	find_index_of_max(t_pile *pile)
{
	int	max;
	int	i;
	int	index;

	max = pile->tab[0];
	i = 0;
	index = 0;
	while (++i < pile->size)
	{
		if (max < pile->tab[i])
		{
			max = pile->tab[i];
			index = i;
		}
	}
	return (index);
}

void	best_rotation_to_put_min_on(t_pile *pile)
{
	int	index;
	int	min;

	index = find_index_of_min(pile);
	min = pile->tab[index];
	while (min != pile->tab[0])
	{
		if (index <= (pile->size) / 2)
			ft_ra(pile);
		else
			ft_rra(pile);
	}
}

int	find_sup(t_pile *pile_a, t_pile *pile_b, int index_of_nb_in_b)
{
	int	i;
	int	index_of_min_in_a;
	int	index_of_max_in_a;

	index_of_min_in_a = find_index_of_min(pile_a);
	index_of_max_in_a = find_index_of_max(pile_a);
	if (pile_b->tab[index_of_nb_in_b] > pile_a->tab[index_of_max_in_a])
		return (index_of_min_in_a);
	i = -1;
	while (++i < pile_a->size)
		if (pile_a->tab[i] > pile_b->tab[index_of_nb_in_b]
			&& pile_a->tab[index_of_max_in_a] > pile_a->tab[i])
			index_of_max_in_a = i;
	return (index_of_max_in_a);
}

int	valeur_absolue(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}
