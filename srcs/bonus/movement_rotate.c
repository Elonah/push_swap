/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:14:19 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/25 05:18:09 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_rotate(t_pile *pile)
{
	int	i;
	int	tmp;
	int	mohaavaitraison;

	mohaavaitraison = pile->tab[0];
	i = 0;
	while (i < pile->size)
	{
		tmp = pile->tab[0];
		pile->tab[0] = pile->tab[pile->size - i];
		pile->tab[pile->size - i] = tmp;
		i++;
	}
	pile->tab[pile->size - 1] = mohaavaitraison;
}

void	ft_ra(t_pile *pile_a)
{
	ft_rotate(pile_a);
}

void	ft_rb(t_pile *pile_b)
{
	ft_rotate(pile_b);
}

void	ft_rr(t_pile *pile_a, t_pile *pile_b)
{
	ft_rotate(pile_a);
	ft_rotate(pile_b);
}
