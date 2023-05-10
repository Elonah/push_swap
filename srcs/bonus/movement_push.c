/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 05:12:44 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/25 05:34:09 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_push(t_pile *pile_agrandie, t_pile *pile_retrecie)
{
	int	i;
	int	j;
	int	tmp;

	if (pile_retrecie->size > 0)
	{
		i = pile_agrandie->size + 1;
		while (--i > 0)
		{
			tmp = pile_agrandie->tab[pile_agrandie->size];
			pile_agrandie->tab[pile_agrandie->size]
				= pile_agrandie->tab[pile_agrandie->size - i];
			pile_agrandie->tab[pile_agrandie->size - i] = tmp;
		}
		pile_agrandie->size++;
		pile_agrandie->tab[0] = pile_retrecie->tab[0];
		j = -1;
		while (++j < pile_retrecie->size - 1)
		{
			tmp = pile_retrecie->tab[j];
			pile_retrecie->tab[j] = pile_retrecie->tab[j + 1];
			pile_retrecie->tab[j + 1] = tmp;
		}
		pile_retrecie->size--;
	}
}

void	ft_pa(t_pile *pile_a, t_pile *pile_b)
{
	ft_push(pile_a, pile_b);
}

void	ft_pb(t_pile *pile_a, t_pile *pile_b)
{
	ft_push(pile_b, pile_a);
}
