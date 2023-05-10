/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_swap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:13:43 by ejacquel          #+#    #+#             */
/*   Updated: 2023/05/04 00:19:50 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swap(t_pile *pile)
{
	int	tmp;

	if (pile->size >= 2)
	{
		tmp = pile->tab[0];
		pile->tab[0] = pile->tab[1];
		pile->tab[1] = tmp;
	}
}

void	ft_sa(t_pile *pile_a)
{
	ft_swap(pile_a);
}

void	ft_sb(t_pile *pile_b)
{
	ft_swap(pile_b);
}

void	ft_ss(t_pile *pile_a, t_pile *pile_b)
{
	ft_swap(pile_a);
	ft_swap(pile_b);
}
