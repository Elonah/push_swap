/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 03:37:50 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/21 02:52:06 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_all_in_b_and_pre_sort(t_pile *pile_a, t_pile *pile_b)
{
	int	i;
	int	median;

	i = 0;
	while (pile_a->size != 3)
	{
		median = find_median(pile_a);
		if (pile_a->tab[0] > median)
			ft_pb(pile_a, pile_b);
		else
			ft_ra(pile_a);
	}
	algo_three(pile_a);
}

t_rotations_needed	best_price(t_pile *pile_a, t_pile *pile_b)
{
	int					index;
	t_rotations_needed	random;
	t_rotations_needed	best;

	best.total_of_rotations = INT_MAX;
	index = -1;
	while (++index < pile_b->size)
	{
		random.price_b = nb_rotation(pile_b, index);
		random.price_a = nb_rotation(pile_a, find_sup(pile_a, pile_b, index));
		random.total_of_rotations = total_rotation(random.price_a,
				random.price_b);
		if (best.total_of_rotations > random.total_of_rotations)
		{
			best.total_of_rotations = random.total_of_rotations;
			best.price_b = random.price_b;
			best.price_a = random.price_a;
		}
	}
	return (best);
}

void	do_rotations2(t_pile *pile_a, t_pile *pile_b, t_rotations_needed best)
{
	while (best.price_b < 0)
	{
		if (best.price_a < 0)
		{
			ft_rr(pile_a, pile_b);
			best.price_a++;
		}
		else
			ft_rb(pile_b);
		best.price_b++;
	}
	while (best.price_a < 0)
	{
		ft_ra(pile_a);
		best.price_a++;
	}
}

void	do_rotations(t_pile *pile_a, t_pile *pile_b, t_rotations_needed best)
{
	while (best.price_b > 0)
	{
		if (best.price_a > 0)
		{
			ft_rrr(pile_a, pile_b);
			best.price_a--;
		}
		else
			ft_rrb(pile_b);
		best.price_b--;
	}
	while (best.price_a > 0)
	{
		ft_rra(pile_a);
		best.price_a--;
	}
	do_rotations2(pile_a, pile_b, best);
}

void	algo_all(t_pile *pile_a, t_pile *pile_b)
{
	t_rotations_needed	best;

	push_all_in_b_and_pre_sort(pile_a, pile_b);
	while (pile_b->size != 0)
	{
		best = best_price(pile_a, pile_b);
		do_rotations(pile_a, pile_b, best);
		ft_pa(pile_a, pile_b);
	}
	best_rotation_to_put_min_on(pile_a);
}
