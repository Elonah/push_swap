/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_rotate.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:14:19 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/14 04:18:23 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putstr_fd("ra\n", 1);
}

void	ft_rb(t_pile *pile_b)
{
	ft_rotate(pile_b);
	ft_putstr_fd("rb\n", 1);
}

void	ft_rr(t_pile *pile_a, t_pile *pile_b)
{
	ft_rotate(pile_a);
	ft_rotate(pile_b);
	ft_putstr_fd("rr\n", 1);
}
