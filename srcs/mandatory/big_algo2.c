/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_algo2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 02:51:49 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/21 02:52:16 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	nb_rotation(t_pile *pile, int index_of_the_nb)
{
	int	nb_of_rotations;

	if (index_of_the_nb <= (pile->size) / 2)
		nb_of_rotations = -index_of_the_nb;
	else
		nb_of_rotations = (pile->size) - index_of_the_nb;
	return (nb_of_rotations);
}

int	total_rotation(int price_a, int price_b)
{
	int	a;
	int	b;

	a = valeur_absolue(price_a);
	b = valeur_absolue(price_b);
	if ((price_a < 0 && price_b < 0) || (price_a > 0 && price_b > 0))
	{
		if (a >= b)
			return (a);
		else
			return (b);
	}
	return (a + b);
}
