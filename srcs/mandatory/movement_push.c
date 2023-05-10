/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_push.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ejacquel <ejacquel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 04:16:45 by ejacquel          #+#    #+#             */
/*   Updated: 2023/04/20 22:45:44 by ejacquel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//void	ft_rotatedown(t_pile *pile)
//{
//	int	temp;

//	temp = pile->size;
//	while (--temp > 0)
//		pile->tab[temp] = pile->tab[temp - 1];
//}

//int	pushswap_push(t_pile *dest, t_pile *src, char c, int *tab)
//{
//	int	temp;
//	int	i;

//	if (!src->size)
//		return (ft_printf("%r\t\tpush %c FAILED%0\n", c));
//	temp = src->size--;
//	dest->size++;
//	ft_rotatedown(dest);
//	dest->tab[0] = tab[0];
//	i = 0;
//	while (++i < temp)
//		tab[i - 1] = tab[i];
//	return (ft_printf("p%c\n", c));
//}

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
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_pile *pile_a, t_pile *pile_b)
{
	ft_push(pile_b, pile_a);
	ft_putstr_fd("pb\n", 1);
}
