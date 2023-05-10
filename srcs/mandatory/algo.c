/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 02:45:07 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/25 04:32:28 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	algo_five(t_pile *pile_a, t_pile *pile_b)
{
	best_rotation_to_put_min_on(pile_a);
	ft_pb(pile_a, pile_b);
	best_rotation_to_put_min_on(pile_a);
	ft_pb(pile_a, pile_b);
	algo_three(pile_a);
	ft_pa(pile_a, pile_b);
	ft_pa(pile_a, pile_b);
}

void	algo_three(t_pile *pile_a)
{
	int	index;
	int	max;

	index = find_index_of_max(pile_a);
	max = pile_a->tab[index];
	if (max == pile_a->tab[1])
		ft_rra(pile_a);
	if (max == pile_a->tab[0])
		ft_ra(pile_a);
	if (pile_a->tab[0] > pile_a->tab[1])
		ft_sa(pile_a);
}

void	algo_two(t_pile *pile_a)
{
	if (pile_a->tab[0] > pile_a->tab[1])
		ft_sa(pile_a);
}

int	ft_algo(t_pile *pile_a, t_pile *pile_b)
{
	if (pile_a->size == 1)
		;
	else if (pile_a->size == 2)
		algo_two(pile_a);
	else if (pile_a->size == 3)
		algo_three(pile_a);
	else if (pile_a->size == 5)
		algo_five(pile_a, pile_b);
	else
		algo_all(pile_a, pile_b);
	if (!checksort(pile_a))
	{
		free (pile_a->tab);
		free (pile_b->tab);
		ft_error(5);
		exit(1);
	}
	return (0);
}
