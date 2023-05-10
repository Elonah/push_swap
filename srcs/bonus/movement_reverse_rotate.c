/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_reverse_rotate.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:15:36 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/25 05:17:46 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_reverse_rotate(t_pile *pile)
{
	int	i;
	int	tmp;
	int	mohaavaitraison;

	mohaavaitraison = pile->tab[pile->size - 1];
	i = pile->size;
	while (i > 0)
	{
		tmp = pile->tab[0];
		pile->tab[0] = pile->tab[pile->size - i];
		pile->tab[pile->size - i] = tmp;
		i--;
	}
	pile->tab[0] = mohaavaitraison;
}

void	ft_rra(t_pile *pile_a)
{
	ft_reverse_rotate(pile_a);
}

void	ft_rrb(t_pile *pile_b)
{
	ft_reverse_rotate(pile_b);
}

void	ft_rrr(t_pile *pile_a, t_pile *pile_b)
{
	ft_reverse_rotate(pile_a);
	ft_reverse_rotate(pile_b);
}
